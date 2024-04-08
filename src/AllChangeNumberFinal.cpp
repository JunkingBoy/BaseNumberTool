#include "..\\headfile\\numberImp.hpp"
#include "..\\headfile\\numberFun.hpp"

int main()
{
    map<string, string> data = NumberFunction::get_info_from_input("101010.110", "8");
    Number num(data["decimal"], data["part"], data["symbol"], data["base"]);
    string val = num.ret_data();
    string binaryStr = num.binary_to_hex(val, "decimal");
    cout << "Decimal number change to binary number of ->" << val << "\t:\t" << binaryStr << endl;
    return 0;
}
