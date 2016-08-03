#include <gtest/gtest.h>
#include "../SuchenStatischenTexten/TextWord.h"

TEST(Unittest_TextWord, Word){
	TextWord word("blub", 0);
	EXPECT_EQ("blub", word.word());
}

TEST(Unittest_TextWord, ExactMatchTRUE){
	TextWord word("banana", 0);
	EXPECT_TRUE(word.exactMatch("banana"));
}

TEST(Unittest_TextWord, ExactMatchFALSE){
	TextWord word("banana" ,0);
	EXPECT_FALSE(word.exactMatch("apple"));
}