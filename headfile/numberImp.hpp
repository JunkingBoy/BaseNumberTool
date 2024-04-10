#ifndef __NUMBRE_IMP__
#define __NUMBER_IMP__

#include "number.hpp"

inline string Number::int_to_binary(const string& val) {
	string result = "";
	int tempNum = stoi(val);

	if (tempNum == 0)
	{
		return "0";
	}

	while (tempNum > 0)
	{
		// 除二取余法
		int ans = tempNum % 2;
		result = to_string(ans) + result;
		tempNum /= 2;
	}

	return result;
}

inline string Number::binary_to_int(const string& val) {
	string result;
	int ansInt = 0;
	int intPow = 1;

	for (int i = val.length() - 1; i >= 0; --i)
	{
		if (val[i] == '1')
		{
			ansInt += intPow;
		}
		intPow *= 2;
	}

	result = to_string(ansInt);

	return result;
}

inline string Number::decimal_to_binary(const string& val) {
	string result = "";
	double tempNum = stod("0." + val); // 注意stoi和stod的使用	

	// 乘二取整
	while (tempNum != 0)
	{
		tempNum *= 2;
		int intPart = static_cast<int>(tempNum);
		result += to_string(intPart);
		tempNum -= intPart;
	}

	return result;
}

inline string Number::binary_to_decimal(const string& val) {
	string result;
	double ansDec = 0;
	double decPow = 0.5;

	for (int i = 0; i < val.length(); i++)
	{
		if (val[i] == '1')
		{
			ansDec += decPow;
		}
		decPow /= 2;
	}

	// 处理浮点数补位0
	string tempAns = to_string(ansDec);
	size_t pos = tempAns.find_last_not_of('0');
	if (pos != string::npos && tempAns[pos] == '.')
	{
		pos--; // 如果小数点后的最后一个非零数字是小数点本身，则再向前一位,如0.025
	}
	if (pos != string::npos)
	{
		tempAns = tempAns.substr(0, pos + 1);
	}

	result = tempAns;
	return result;
}

inline string Number::octal_to_binary(const string& val) {
	/*
	* 八进制和十进制变为二进制不同的是
	* 八进制是每一位数变为二进制数
	* 十进制是整数部分和小数部分
	* 八进制数三位一组
	*/
	string result;
	string tempResStr = "";
	for (int i = 0; i < val.length(); i++)
	{
		char tempStr = val[i];
		int tempNum = atoi(&tempStr);
		while (tempNum > 0)
		{
			int ans = tempNum % 2;
			tempResStr = to_string(ans) + tempResStr;
			tempNum /= 2;
		}
		if (tempResStr.length() != 3)
		{
			int tempIntAdd = 3 - tempResStr.length();
			tempResStr.insert(0, tempIntAdd, '0');
		}
		result =  result + tempResStr;
		tempResStr = "";
	}

	return result;
}

inline string Number::binary_to_octal(const string& val, const string& part) {
	/*
	* 三位一组
	* 二进制数从后往前三位一组
	* 每组进行变八进制计算
	*/
	string result;
	string tempRes = "";
	string tempVal = val;
	int ansInt = 0;
	int intPow = 1;
	int time = 0;

	if (part == "decimal")
	{
		// 长度小于3,补0到长度为3
		if (tempVal.length() < 3)
		{
			int zeroAdd = 3 - tempVal.length();
			tempVal = tempVal + string(zeroAdd, '0');
		}
	}

	for (int i = tempVal.length() - 1; i >= 0; --i)
	{
		if (tempVal[i] == '1')
		{
			ansInt += intPow;
		}
		time++;
		if (time % 3 == 0 || i == 0)
		{
			// 重置time并且重置intPow和重置ansInt
			tempRes = to_string(ansInt) + tempRes;
			time = 0;
			intPow = 1;
			ansInt = 0;
		}
		else
		{
			intPow *= 2;
		}
	}

	result = tempRes;
	return result;
}

inline string Number::hex_to_binary(const string& val) {
	/*
	* 四位一组
	* 每一位16进制数变为四位二进制数
	* 不满补位0
	*/
	string result;
	string tempRes = "";

	for (int i = val.length() - 1; i >= 0; --i)
	{
		if (val[i] >= 'A' && val[i] <= 'F')
		{
			string tempCalStr = char_to_string_hex.at(val[i]);
			tempCalStr = int_to_binary(tempCalStr);
			tempRes = tempCalStr + tempRes;
		}
		else
		{
			char tempChar = val[i];
			int tempNum = atoi(&tempChar);
			string tempResStr = "";

			while (tempNum > 0)
			{
				int ans = tempNum % 2;
				tempResStr = to_string(ans) + tempResStr;
				tempNum /= 2;
			}
			if (tempResStr.length() != 4)
			{
				int tempIntAdd = 4 - tempResStr.length();
				tempResStr.insert(0, tempIntAdd, '0');
			}
			tempRes = tempResStr + tempRes;
			tempResStr = "";
		}
	}

	result = tempRes;
	return result;
}

inline string Number::binary_to_hex(const string& val, const string& part) {
	/*
	* 从后往前
	* 四位一组
	* 重置数
	*/
	string result;
	string tempRes = "";
	string tempVal = val;
	int ansInt = 0;
	int intPow = 1;
	int time = 0;

	if (part == "decimal")
	{
		// 长度小于4,补0到长度为4
		if (tempVal.length() < 4)
		{
			int zeroAdd = 4 - tempVal.length();
			tempVal = tempVal + string(zeroAdd, '0');
		}
	}

	for (int i = tempVal.length() - 1; i >= 0; --i)
	{
		if (tempVal[i] == '1')
		{
			ansInt += intPow;
		}
		time++;
		if (time % 4 == 0 || i == 0)
		{
			if (ansInt >= 10 && ansInt <= 15)
			{
				tempRes = string_to_char_hex.at(to_string(ansInt)) + tempRes;
			}
			else
			{
				tempRes = to_string(ansInt) + tempRes;
			}
			time = 0;
			intPow = 1;
			ansInt = 0;
		}
		else
		{
			intPow *= 2;
		}
	}

	result = tempRes;
	return result;
}

#endif // !__NUMBRE_IMP__