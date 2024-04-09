#include <gtest/gtest.h>
#include "../headfile/numberFun.hpp"

using namespace NumberFunction;

// integer no decimal
TEST(GetInfoFromInputTest, PositiveIntegerTest) {
    string val = "123456";
    string baseNumber = "10";
    map<string, string> result = get_info_from_input(val, baseNumber);
    EXPECT_EQ(result["integer"], val);
    EXPECT_EQ(result["decimal"], "0");
    EXPECT_EQ(result["baseNumber"], baseNumber);
    EXPECT_EQ(result["symbol"], "0");
    EXPECT_EQ(result["part"], "10");
    EXPECT_EQ(result["answer"], val);
}

// integer and symbol = 1
TEST(GetInfoFromInputTest, PositiveIntegerAndSymbolTest) {
    string val = "-123456";
    string baseNumber = "10";
    map<string, string> result = get_info_from_input(val, baseNumber);
    EXPECT_EQ(result["integer"], "123456");
    EXPECT_EQ(result["decimal"], "0");
    EXPECT_EQ(result["baseNumber"], baseNumber);
    EXPECT_EQ(result["symbol"], "1");
    EXPECT_EQ(result["part"], "10");
    EXPECT_EQ(result["answer"], val);
}

// integer and decimal
TEST(GetInfoFromInputTest, PositiveIntegerAndDecimalTest) {
    string val = "123456.789";
    string baseNumber = "10";
    map<string, string> result = get_info_from_input(val, baseNumber);
    EXPECT_EQ(result["integer"], "123456");
    EXPECT_EQ(result["decimal"], "789");
    EXPECT_EQ(result["baseNumber"], baseNumber);
    EXPECT_EQ(result["symbol"], "0");
    EXPECT_EQ(result["part"], "11");
    EXPECT_EQ(result["answer"], val);
}

// integer and decimal and symbol = 1
TEST(GetInfoFromInputTest, PositiveIntegerAndDecimalAndSymbolTest) {
    string val = "-123456.789";
    string baseNumber = "10";
    map<string, string> result = get_info_from_input(val, baseNumber);
    EXPECT_EQ(result["integer"], "123456");
    EXPECT_EQ(result["decimal"], "789");
    EXPECT_EQ(result["baseNumber"], baseNumber);
    EXPECT_EQ(result["symbol"], "1");
    EXPECT_EQ(result["part"], "11");
    EXPECT_EQ(result["answer"], val); // 断言失败函数不会停止
}

// change info from map and change integer
TEST(change_info_from_map, IntegerPartChuangeTest) {
    map<string, string> dataMap = {
        {"integer", "123"},
        {"decimal", "0"},
        {"symbol", "0"},
        {"part", "10"},
        {"base", "10"},
        {"answer", "123"}
    };

    string changePart = "integer";
    string changeVal = "456";

    auto result = change_info_from_map(dataMap, changePart, changeVal);

    ASSERT_EQ(result["integer"], changeVal); // 断言失败函数停止
    ASSERT_EQ(result["answer"], "456");
}

// change info from map and change decimal
TEST(change_info_from_map, DecimalPartChuangeTest) {
    map<string, string> dataMap = {
        {"integer", "123"},
        {"decimal", "456"},
        {"symbol", "0"},
        {"part", "10"},
        {"base", "10"},
        {"answer", "123"}
    };

    string changePart = "decimal";
    string changeVal = "789";

    auto result = change_info_from_map(dataMap, changePart, changeVal);

    ASSERT_EQ(result["decimal"], changeVal);
    ASSERT_EQ(result["answer"], "123.789");
}

// change info from map and change symbol
TEST(change_info_from_map, SymbolPartChuangeTest) {
        map<string, string> dataMap = {
        {"integer", "123"},
        {"decimal", "456"},
        {"symbol", "0"},
        {"part", "10"},
        {"base", "10"},
        {"answer", "123"}
    };

    string changePart = "symbol";
    string changeVal = "1";

    auto result = change_info_from_map(dataMap, changePart, changeVal);

    ASSERT_EQ(result["symbol"], "0");
}

// change info from map and change part
TEST(change_info_from_map, PartPartChuangeTest) {
    map<string, string> dataMap = {
        {"integer", "123"},
        {"decimal", "456"},
        {"symbol", "0"},
        {"part", "10"},
        {"base", "10"},
        {"answer", "123"}
    };

    string changePart = "part";
    string changeVal = "11";

    auto result = change_info_from_map(dataMap, changePart, changeVal);

    ASSERT_EQ(result["part"], "10");
}

// change info from map and change base
TEST(change_info_from_map, BasePartChuangeTest) {
    map<string, string> dataMap = {
        {"integer", "123"},
        {"decimal", "456"},
        {"symbol", "0"},
        {"part", "10"},
        {"base", "10"},
        {"answer", "123"}
    };

    string changePart = "base";
    string changeVal = "8";

    auto result = change_info_from_map(dataMap, changePart, changeVal);

    ASSERT_EQ(result["base"], "10");
}

// change info from map and change answer
TEST(change_info_from_map, AnswerPartChuangeTest) {
    map<string, string> dataMap = {
        {"integer", "123"},
        {"decimal", "456"},
        {"symbol", "0"},
        {"part", "10"},
        {"base", "10"},
        {"answer", "123"}
    };

    string changePart = "answer";
    string changeVal = "456";

    auto result = change_info_from_map(dataMap, changePart, changeVal);

    ASSERT_EQ(result["answer"], "123");
}