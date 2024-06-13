#ifndef _HEX_HELPER_H_
#define _HEX_HELPER_H_

#include <string>
#include <memory>


class HexHelper
{
public:
	/// <summary>
	/// RawDataToHexString
	/// 把字节流转成16进制描述的字符串
	/// </summary>
	/// <param name="data"></param>
	/// <param name="data_len"></param>
	/// <param name="to_lower">默认表示10-16的字母a-f用小写，false时用大写</param>
	/// <returns></returns>
	static std::string RawDataToHexString(const unsigned char* data, size_t data_len, bool to_lower = true);


	/// <summary>
	/// HexStringToRawData
	/// 把描述16进制的数据转成原始数据。
	/// </summary>
	/// <param name="hex_str">长度不能为0，会返回false。数据不合法也会导致返回false</param>
	/// <param name="ret_raw_buf">返回在函数内部创建的数据数组，由上层负责释放</param>
	/// <param name="ret_raw_data_len">返回的数据的长度</param>
	/// <returns></returns>
	static bool HexStringToRawData(unsigned char** ret_raw_buf, size_t* ret_raw_data_len, const std::string& hex_str);
	
	// 使用智能指针返回的版本， 使用者不用担心忘记释放buf的问题。
	static bool HexStringToRawData(
		std::shared_ptr<unsigned char[]>* p_buf_shared_ptr, 
		size_t* ret_raw_data_len, 
		const std::string& hex_str
	);
private:
	static bool _DecodeHexValue(unsigned char* p_target, char high_4bit, char low_4bit);
	static bool _HexCharToValue(unsigned char* p_target, char ch_hex);
};


#endif
