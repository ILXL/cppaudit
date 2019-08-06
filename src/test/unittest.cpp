#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"

// Place unit tests here

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);    
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
    return RUN_ALL_TESTS();
}
