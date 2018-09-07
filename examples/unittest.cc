#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include "gtest_ext.h"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;



TEST(Restaurant, OutputFormat)
{
  std::string expected = "Please input meal cost: Please input tip "
                      "percentage: \nRestaurant Bill\n====================\n"
                      "Subtotal: $34.00\nTaxes: $2.55\nTip: $5.10\n"
                      "====================\nTotal: $41.65\n";
  ASSERT_MAIN_OUTPUT_EQ("restaurant", "34 15", expected);
}

TEST(Restaurant, MealCost)
{
  srand (time(NULL));
  for(int i = 0; i < 10; i++)
  {
    double meal_cost = (int)((double)rand() / RAND_MAX * 100) / 100.0 ;
    std::string meal_cost_string = "Subtotal: $" + to_string_double(meal_cost);
    std::string input = to_string_double(meal_cost) + " 15";
    ASSERT_MAIN_OUTPUT_THAT("restaurant", input, HasSubstr(meal_cost_string));
  }
}

TEST(Restaurant, Taxes)
{
  for(int i = 0; i < 10; i++)
  {
    double meal_cost = (int)((double)rand() / RAND_MAX * 100) / 100.0 ;
    double taxes = meal_cost*0.075 ;
    std::string taxes_string = "Taxes: $" + to_string_double(taxes);
    std::string input = to_string_double(meal_cost) + " 15";
    ASSERT_MAIN_OUTPUT_THAT("restaurant", input, HasSubstr(taxes_string));
  }
}

TEST(Restaurant, Tip)
{
  for(int i = 0; i < 10; i++)
  {
    double meal_cost = (int)((double)rand() / RAND_MAX * 100) / 100.0 ;
    double tip = (int)(((20 - 5) * ( (double)rand() / (double)RAND_MAX ) + 5)*100)/100.0;
    std::string tip_string = "Tip: $" + to_string_double(meal_cost*tip/100);
    std::string input = to_string_double(meal_cost) + " " + to_string_double(tip);
    ASSERT_MAIN_OUTPUT_THAT("restaurant", input, HasSubstr(tip_string));
  }
}

TEST(Restaurant, Total)
{
  for(int i = 0; i < 10; i++)
  {
    double meal_cost = (int)((double)rand() / RAND_MAX * 100) / 100.0 ;
    double tip = (int)(((20 - 5) * ( (double)rand() / (double)RAND_MAX ) + 5)*100)/100.0;
    double total = meal_cost + meal_cost * 0.075 + meal_cost * tip / 100;
    std::string total_string = "Total: $" + to_string_double(total);
    std::string input = to_string_double(meal_cost) + " " + to_string_double(tip);
    ASSERT_MAIN_OUTPUT_THAT("restaurant", input, HasSubstr(total_string));
  }
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
