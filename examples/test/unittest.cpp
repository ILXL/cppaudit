#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"

// Place unit tests here
TEST(ExecutableOutput, Equal) {
	ASSERT_EXECEQ("restaurant", "", "Restaurant: 27\n");
}

TEST(ExecutableOutput, Forcefail_expected_missing_Chars) {
	ASSERT_EXECEQ("restaurant", "", "Restaurant: ");
}

TEST(ExecutableOutput, Forcefail_program_missing_Chars) {
	ASSERT_EXECEQ("restaurant", "", "Restaurant: 27\nabc");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
