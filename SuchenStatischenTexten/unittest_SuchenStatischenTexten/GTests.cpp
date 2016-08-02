#include <gtest/gtest.h>
#include "../SuchenStatischenTexten/IOParser.h"
#include <string>

TEST(IOParser, IOImport){
	std::string input = IOImport("GTestIOImport.txt");
	EXPECT_EQ("Das ist ein IOImport Test.", input);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}