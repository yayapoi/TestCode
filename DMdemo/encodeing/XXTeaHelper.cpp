#include "XXTeaHelper.h"
#include <memory>
#include "HexHelper.h"

#include <memory>

#include <string.h>
std::string XXTeaHelper::XXTeaEncryptToHex(const std::string& contents, const std::string& secret, bool to_lower)
{
	// 用于加密的数据字节数必须是4的倍数。 并且额外增加4字节，用于记录原始数据的长度
	size_t need_buf_size = (contents.length() + 3) / 4 * 4 + 4;
	std::unique_ptr<unsigned char[]> enc_buf(new unsigned char[need_buf_size]);
    memset(enc_buf.get(), 0x0, need_buf_size);
	memcpy(enc_buf.get(), contents.c_str(), contents.length());

	// 设置原始数据的长度
	*((uint32_t*)&enc_buf[need_buf_size - 4]) = static_cast<uint32_t>(contents.length());

	uint32_t keys[4];
	_SetupKeys(keys, secret);

	_XXTeaEncrypt(reinterpret_cast<uint32_t*>(enc_buf.get()), need_buf_size / 4, keys);
	return HexHelper::RawDataToHexString(enc_buf.get(), need_buf_size, to_lower);
}

bool XXTeaHelper::XXTeaDecryptHex(std::string* ret_decoded_contents, const std::string& hex_encoded_contents, const std::string& secret)
{
	std::shared_ptr<unsigned char[]> data_buf;
	size_t enc_data_len = 0;
	if (!HexHelper::HexStringToRawData(&data_buf, &enc_data_len, hex_encoded_contents)) {
		return false;
	}

	if (enc_data_len % 4 != 0) {
		return false;
	}

	uint32_t keys[4];
	_SetupKeys(keys, secret);

	// 解密以后的数据，还是存放在data_buf
	_XXTeaDecrypt(reinterpret_cast<uint32_t*>(data_buf.get()), enc_data_len / 4, keys);

	uint32_t origin_len = *((uint32_t*)(data_buf.get() + enc_data_len - 4));
	if (origin_len > enc_data_len - 4) { // 保存原始数据长度占用了4字节，原始数据长度不可能超过解码后的数据长度-4。
		return false;
	}

	*ret_decoded_contents = std::string(reinterpret_cast<const char*>(data_buf.get()), origin_len);
	return true;
}


// 用户定义的密钥数据只会用到前面的16字节
void XXTeaHelper::_SetupKeys(uint32_t keys[4], const std::string& user_secret_key)
{
	const size_t Keys_Total_Size = sizeof(uint32_t) * 4;
	memset(keys, 0x0, Keys_Total_Size);
	if (user_secret_key.length() >= Keys_Total_Size) {
		memcpy(keys, user_secret_key.c_str(), Keys_Total_Size);
	}
	else {
		memcpy(keys, user_secret_key.c_str(), user_secret_key.length());
	}
}

// 输入和输出的长度一致， 输出直接覆盖了原来的输入。key只接受16字节
void XXTeaHelper::_XXTeaEncrypt(uint32_t* p_src_values, size_t value_count, const uint32_t keys[4])
{
	// 算法拷贝自c#版。
	if (!p_src_values || value_count <= 0) {
		return;
	}
	int32_t n = static_cast<int32_t>(value_count - 1);
	uint32_t z = p_src_values[n], y = p_src_values[0], delta = 0x9E3779B9, sum = 0, e;
	int32_t p, q = 6 + 52 / (n + 1);
	while (q-- > 0)
	{
		sum = sum + delta;
		e = sum >> 2 & 3;
		for (p = 0; p < n; p++)
		{
			y = p_src_values[p + 1];
			z = p_src_values[p] += (z >> 5 ^ y << 2) + (y >> 3 ^ z << 4) ^ (sum ^ y) + (keys[p & 3 ^ e] ^ z);
		}
		y = p_src_values[0];
		z = p_src_values[n] += (z >> 5 ^ y << 2) + (y >> 3 ^ z << 4) ^ (sum ^ y) + (keys[p & 3 ^ e] ^ z);
	}
}

// 输入和输出的长度一致， 输出直接覆盖了原来的输入。key只接受16字节
void XXTeaHelper::_XXTeaDecrypt(uint32_t* p_src_values, size_t value_count, const uint32_t keys[4])
{
	// 算法拷贝自c#版。
	if (!p_src_values || value_count <= 0) {
		return;
	}
	int32_t n = static_cast<int32_t>(value_count - 1);
	uint32_t z = p_src_values[n], y = p_src_values[0], delta = 0x9E3779B9, sum, e;
	int32_t p, q = 6 + 52 / (n + 1);
	sum = (uint32_t)(q * delta);
	while (sum != 0)
	{
		e = sum >> 2 & 3;
		for (p = n; p > 0; p--)
		{
			z = p_src_values[p - 1];
			y = (p_src_values[p] -= (z >> 5 ^ y << 2) + (y >> 3 ^ z << 4) ^ (sum ^ y) + (keys[p & 3 ^ e] ^ z));
		}
		z = p_src_values[n];
		y = (p_src_values[0] -= (z >> 5 ^ y << 2) + (y >> 3 ^ z << 4) ^ (sum ^ y) + (keys[p & 3 ^ e] ^ z));
		sum = sum - delta;
	}
}
