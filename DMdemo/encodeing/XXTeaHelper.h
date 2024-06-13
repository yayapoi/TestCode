#ifndef _XXTEA_HELPER_H_
#define _XXTEA_HELPER_H_

#include <string>



class XXTeaHelper
{
public:
	static std::string XXTeaEncryptToHex(const std::string& contents, const std::string& secret, bool to_lower = true);
	static bool XXTeaDecryptHex(std::string* ret_decoded_contents, const std::string& hex_encoded_contents, const std::string& secret);
	
private:
	// 用户定义的密钥数据只会用到前面的16字节
	static void _SetupKeys(uint32_t keys[4], const std::string& user_secret_key);

	// 输入和输出的长度一致， 输出直接覆盖了原来的输入。key只接受16字节
	static void _XXTeaEncrypt(uint32_t* p_src_values, size_t value_count, const uint32_t keys[4]);
	
	// 输入和输出的长度一致， 输出直接覆盖了原来的输入。key只接受16字节
	static void _XXTeaDecrypt(uint32_t* p_src_values, size_t value_count, const uint32_t keys[4]);
};



#endif
