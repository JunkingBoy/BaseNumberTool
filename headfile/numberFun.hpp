#ifndef __NUMBER_FUN__
#define __NUMBER_FUN__

#include "windowsFrame.hpp"

namespace NumberFunction {
	map<string, string> get_info_from_input(const string& val, const string& baseNumber) {
		string result;
		map<string, string> mapResult;
		mapResult["base"] = baseNumber;
		mapResult["symbol"] = "0"; // 0为正1为负

		if (val[0] == '-')
		{
			mapResult["symbol"] = "1";
		}

		for (auto& ch : val)
		{
			if (ch != '-')
			{
				result += ch;
			}
		}

		size_t dotPos = result.find('.');
		if (dotPos != string::npos)
		{
			// 取整
			string intPartStr = result.substr(0, dotPos);
			// 取小数
			string decimalPartStr = result.substr(dotPos + 1);

			mapResult["integer"] = intPartStr;
			mapResult["decimal"] = decimalPartStr;
			mapResult["part"] = "11"; // 有整数部分有小数部分
			mapResult["answer"] = intPartStr + '.' + decimalPartStr;
		}
		else
		{
			mapResult["integer"] = result;
			mapResult["decimal"] = "0";
			mapResult["part"] = "10"; // 有整数部分没有小数部分
			mapResult["answer"] = result;
		}

		return mapResult;
	}

	map<string, string> change_info_from_map(map<string, string>& dataMap, const string& part, const string& val) {
		map<string, string> mapResult = dataMap;

		// symbol、part、base不可变,answer不可显示修改
		if (part != "symbol" || part != "part" || part != "base" || part != "answer")
		{
			if (part == "decimal" && mapResult["part"] == "10")
			{
				mapResult[part] = "0";
			}
			mapResult[part] = val;
		}
		if (mapResult["symbol"] == "0" && mapResult["part"] == "10")
		{
			mapResult["answer"] = mapResult["integer"];
		}else if (mapResult["symbol"] == "0" && mapResult["part"] == "11")
		{
			mapResult["answer"] = mapResult["integer"] + '.' + mapResult["decimal"];
		}else if (mapResult["symbol"] == "1" && mapResult["part"] == "10")
		{
			mapResult["answer"] = "-" + mapResult["integer"];
		}else
		{
			mapResult["answer"] = "-" + mapResult["integer"] + '.' + mapResult["decimal"];
		}

		return mapResult;
	}
}

#endif // !__NUMBER_FUN__
