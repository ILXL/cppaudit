#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"

// Place unit tests here
TEST(SUITE1, STDOUT) {
	ASSERT_EXECEQ("restaurant", "", "Restawrant");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
