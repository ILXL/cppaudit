#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../cppaudit/image_test_utils.h"

using ::testing::HasSubstr;

// Use UnitTestFileManager which renames any existing files
// during the test so they are not clobbered.
class ImageTest : public UnitTestFileManager {
 public:
  ImageTest() : UnitTestFileManager("test_result.bmp") {};

  bool FileCreated() {
    std::ifstream stream;
    stream.open(filename_);
    bool created = stream.good();
    stream.close();
    return created;
  }
};

TEST_F(ImageTest, ExecutesAndExits) {
  // Note: ASSERT_EXECEXIT does not fail when it passes *more* inputs
  // than the program asked for.
  // This will pass even with just the starter code (i.e. if the radius
  // is unused.)
  std::string user_input = "test_result.bmp\n10\n";
  ASSERT_EXECEXIT("main", user_input, 3)
      << "      Your program should ask for the filename and the circle radius";
  EXPECT_TRUE(FileCreated()) << "Your program should save a file based on user input.";
}

TEST_F(ImageTest, NegativeRadius) {
  std::string user_input = "test_result.bmp\n-1\n";
  ASSERT_DURATION_LE(3, {
      ASSERT_EXECTHAT(
          "main", user_input,
          HasSubstr("The radius must be between 1 and 100")) <<
          "Hint: Check that you test the radius entered is in bounds. "
          "The output should follow the exact format of the README.";
    });
  EXPECT_FALSE(FileCreated())
      << "Your program should not save a file when input is invalid.";
}

TEST_F(ImageTest, RadiusTooLarge) {
  std::string user_input = "test_result.bmp\n101\n";
  ASSERT_DURATION_LE(3, {
      ASSERT_EXECTHAT(
          "main", user_input,
          HasSubstr("The radius must be between 1 and 100")) <<
          "Hint: Check that you test the radius entered is in bounds. "
          "The output should follow the exact format of the README.";
    });
  EXPECT_FALSE(FileCreated())
      << "Your program should not save a file when input is invalid.";
}

TEST_F(ImageTest, CreatesImageSize100) {
  // Remove diff image before starting, so that if the test runs successfully
  // it isn't left behind as an artifact from last time.
  std::string diff_image = "expected_v_actual_100.bmp";
  remove(diff_image.c_str());

  std::string user_input = "test_result.bmp\n100\n";
  ASSERT_EXECEXIT("main", user_input, 2);

  // Generate the expectation instead of loading it from a file.
  ASSERT_TRUE(FileCreated()) << "Your program should save a file based on user input.";
  graphics::Image actual;
  ASSERT_TRUE(actual.Load("test_result.bmp"));
  graphics::Image expected(200, 200);
  expected.DrawCircle(100, 100, 100, 0, 0, 255);
  bool match = ImagesMatch(&expected, &actual, diff_image,
      DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "Your image is not quite right. See " << diff_image;
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
