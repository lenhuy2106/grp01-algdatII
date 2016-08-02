#include <gtest/gtest.h>
#include "../SuchenStatischenTexten/SufTree.h"

TEST(Unittest_SufTree, PossibleMatchTRUE){
	SufTree tree("blub");
	EXPECT_TRUE(tree.possibleMatch("blub"));
}

TEST(Unittest_SufTree, PossibleMatchFALSE){
	SufTree tree("blub");
	EXPECT_FALSE(tree.possibleMatch("bu"));
}