#include <gtest/gtest.h>
#include "../SuchenStatischenTexten/IOParser.h"

TEST(Unittest_IOParser, IOImport){
	std::string input = IOHelper::IOImport("unittest_IOParser.txt");

	EXPECT_EQ("Das ist ein IOImport Test", input);
}

TEST(Unittest_IOParser, SplitString){
	std::string input = "Das ist ein IOImport Test";
	std::string arrayList[] = { "Das", "ist", "ein", "IOImport", "Test" };
	std::vector<std::string> expected(arrayList, end(arrayList));

	EXPECT_EQ(expected, IOHelper::splitString(input));
}