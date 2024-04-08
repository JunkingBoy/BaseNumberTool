#ifndef __NUMBER__
#define __NUMBER__

#include "windowsFrame.hpp"

class Number
{
public:
	Number(const string& data, const string& dataPart, const string& dataSymbol, const string& databBaseNumber)
	: data(data), dataPart(dataPart), dataSymbol(dataSymbol), dataBaseNumber(databBaseNumber) {};
	void set_data(string& val) { data = val; }
	string ret_data() const { return data; }
	string get_data_part() const{ return dataPart; }
	string get_data_symbol() const { return dataSymbol; }
	string get_data_base() const { return dataBaseNumber; }
	string int_to_binary(const string&);
	string binary_to_int(const string&);
	string decimal_to_binary(const string&);
	string binary_to_decimal(const string&);
	string octal_to_binary(const string&);
	string binary_to_octal(const string&, const string&);
	string hex_to_binary(const string&);
	string binary_to_hex(const string&, const string&);
private:
	string data, dataPart, dataSymbol, dataBaseNumber;
};

static const map<char, string> char_to_string_hex = {
	{'A', "10"},
	{'B', "11"},
	{'C', "12"},
	{'D', "13"},
	{'E', "14"},
	{'F', "15"}
};

static const map<string, char> string_to_char_hex = {
	{"10", 'A'},
	{"11", 'B'},
	{"12", 'C'},
	{"13", 'D'},
	{"14", 'E'},
	{"15", 'F'}
};

#endif // !__NUMBER__