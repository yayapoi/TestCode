#include "HexHelper.h"


/// <summary>
/// RawDataToHexString
/// 把字节流转成16进制描述的字符串
/// </summary>
/// <param name="data"></param>
/// <param name="data_len"></param>
/// <param name="to_lower">默认表示10-16的字母a-f用小写，false时用大写</param>
/// <returns></returns>
std::string HexHelper::RawDataToHexString(const unsigned char* data, size_t data_len, bool to_lower)
{
	if (!data || data_len <= 0) {
		return "";
	}

	static const char S_Hex_Table_Lower[] = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
	};
	static const char S_Hex_Table_Upper[] = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
	};

	std::string ret_str;
	ret_str.resize(data_len * 2);
	const char* hex_table = to_lower ? S_Hex_Table_Lower : S_Hex_Table_Upper;
	for (int i = 0; i < data_len; i++) {
		ret_str[2 * i] = hex_table[(0xf0 & data[i]) >> 4]; // 高位放在前面
		ret_str[2 * i + 1] = hex_table[0xf & data[i]]; // 低位放在后面
	}
	return ret_str;
}

/// <summary>
/// HexStringToRawData
/// 把描述16进制的数据转成原始数据。
/// </summary>
/// <param name="hex_str">长度不能为0，会返回false。数据不合法也会导致返回false</param>
/// <param name="ret_raw_buf">返回在函数内部创建的数据数组，由上层负责释放</param>
/// <param name="ret_raw_data_len">返回的数据的长度</param>
/// <returns></returns>
bool HexHelper::HexStringToRawData(unsigned char** ret_raw_buf, size_t* ret_raw_data_len, const std::string& hex_str)
{
	// 不接收返回，这个函数就没有意义。
	if (!ret_raw_buf || !ret_raw_data_len) {
		return false;
	}

	if (hex_str.empty() || hex_str.length() % 2 != 0) {
		return false;
	}

	size_t dst_len = hex_str.length() / 2;
	unsigned char* bytes_buf = new unsigned char[dst_len];
	for (int i = 0; i < dst_len; i++) {
		if (!_DecodeHexValue(&bytes_buf[i], hex_str[2 * i], hex_str[2 * i + 1])) {
			delete[]bytes_buf;
			return false;
		}
	}
	*ret_raw_buf = bytes_buf;
	*ret_raw_data_len = dst_len;
	return true;
}

// 使用智能指针返回的版本， 使用者不用担心忘记释放buf的问题。
bool HexHelper::HexStringToRawData(
	std::shared_ptr<unsigned char[]>* p_buf_shared_ptr, 
	size_t* ret_raw_data_len, 
	const std::string& hex_str
)
{
	unsigned char* ret_buf = nullptr;
	if (!HexStringToRawData(&ret_buf, ret_raw_data_len, hex_str)) {
		return false;
	}
	p_buf_shared_ptr->reset(ret_buf);
	return true;
}

bool HexHelper::_DecodeHexValue(unsigned char* p_target, char high_4bit, char low_4bit)
{
	unsigned char target_high, target_low;
	if (!_HexCharToValue(&target_high, high_4bit) || !_HexCharToValue(&target_low, low_4bit)) {
		return false;
	}
	*p_target = (target_high << 4) | target_low;
	return true;
}

bool HexHelper::_HexCharToValue(unsigned char* p_target, char ch_hex)
{
	if (ch_hex >= '0' && ch_hex <= '9') {
		*p_target = ch_hex - '0';
		return true;
	}
	else if (ch_hex >= 'a' && ch_hex <= 'f') {
		*p_target = ch_hex - 'a' + 10;
		return true;
	}
	else if (ch_hex >= 'A' && ch_hex <= 'F') {
		*p_target = ch_hex - 'A' + 10;
		return true;
	}
	else {
		return false;
	}
}
