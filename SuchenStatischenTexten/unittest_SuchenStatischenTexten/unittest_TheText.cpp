#include <gtest/gtest.h>
#include "../SuchenStatischenTexten/TheText.h"

TEST(Unittest_TheText, ExactMatchCountTRUE){
	TheText text("unittest_TheText.txt");
	EXPECT_EQ(3, text.exactMatchCount("Text"));
}

TEST(Unittest_TheText, ExactMatchCountFALSE){
	TheText text("unittest_TheText.txt");
	EXPECT_EQ(0, text.exactMatchCount("blub"));
}

TEST(Unittest_TheText, GetOccurancesTRUE){
	TheText text("unittest_TheText.txt");
	std::vector<unsigned int> expected = {0,5,7};
	EXPECT_EQ(expected, text.getOccurances("Text"));
}

TEST(Unittest_TheText, GetOccurancesFALSE){
	TheText text("unittest_TheText.txt");
	std::vector<unsigned int> expected = {};
	EXPECT_EQ(expected, text.getOccurances("blub"));
}

TEST(Unittest_TheText, Name){
	TheText text("unittest_TheText.txt");
	EXPECT_EQ("unittest_TheText.txt", text.name());
}