#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"

// Place unit tests here
TEST(ExecutableOutput, Equal) {
	ASSERT_EXECEQ("restaurant", "", "Restaurant: 27\n");
	//ASSERT_EQ(1,1);
}

TEST(ExecutableOutput, Forcefail_expected_missing_Chars) {
	ASSERT_EXECEQ("restaurant", "", "Restaurant: ");
}

TEST(ExecutableOutput, Forcefail_program_missing_Chars) {
	ASSERT_EXECEQ("restaurant", "", "Restaurant: 27\nabc");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);    
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
    return RUN_ALL_TESTS();
}
