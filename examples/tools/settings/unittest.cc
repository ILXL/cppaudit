#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../cppaudit/image_test_utils.h"
#include "../../algebra.hpp"

using ::testing::HasSubstr;

TEST(Cube, Cube) {
	ASSERT_THAT(cube(3), 27);
}

TEST(UserInput, AskMealCostAndTip) {
  std::string user_input = "10.00 9.00";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the customer's meal cost and tip percentage.";
}

TEST(Taxes, Taxes1) {
  std::string input = "10.00 9";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", input, HasSubstr("Taxes: $0.75")) << "Hint: Taxes are 7.5% of the $10.00 meal cost. It should display $0.75";
  });
}

TEST(Taxes, Taxes2) {
  std::string input = "34.80 9";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", input, HasSubstr("Taxes: $2.61")) << "Hint: Taxes are 7.5% of the $35.50 meal cost. It should display $2.61";
  });
}

TEST(Tip, ZeroTip) {
  std::string input = "27.50 0";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", input, HasSubstr("Tip: $0.00")) << "Hint: Given a 0% tip percentage and $25.50 meal cost, the tip should display $0.00";
  });
}

TEST(Tip, Tip) {
  std::string input = "54.58 15";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", input, HasSubstr("Tip: $8.19")) << "Hint: Given a 10% tip percentage and $54.58 meal cost, the tip should display $8.19";
  });
}

TEST(Driver, Output) {
  std::string unittest_output =
      "Please input meal cost: Please input tip percentage: \nRestaurant "
      "Bill\n====================\nSubtotal: $314.19\nTaxes: $23.56\nTip: "
      "$40.84\n====================\nTotal: $378.60\n";
  std::string input = "314.19 13";
  ASSERT_EXECEQ("main", input, unittest_output) << "Hint: The output should follow the exact format in README.md. Take note of extra spaces and tabs!";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
