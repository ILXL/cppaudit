#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include "gtest_ext.h"
#include "../algebra.hpp"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;

TEST(CashBack, OutputFormat)
{
   ASSERT_MAIN_OUTPUT_EQ("restaurant", "", "Restaurant: 27\n");
}

TEST(CashBack, FuncTest)
{
      ASSERT_EQ(cube(3), 27);
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
