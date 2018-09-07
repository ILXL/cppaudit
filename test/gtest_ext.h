// This file contains implementations that extend the functionality of the
// google test framework
#include <gtest/gtest.h>
#include <unistd.h>
#include <setjmp.h>
#include <signal.h>
#include <string>
#include <iomanip>

// Run and retrieves the output of an executable program from
// the command line.
//
// @param prog_name name of the executable file
// @param input     keyboard input sent to the program
//
// @return output of the program
std::string main_output(std::string prog_name, std::string input)
{
  FILE *fp = popen(("echo \""+ input +"\" | ./" + prog_name).c_str(), "r");
  char buf[1024];
  std::string output = "";
  while (fgets(buf, 1024, fp)) {
    output += buf;
  }
  pclose(fp);
  return output;
}

// Converts a double value to a formatted string
//
// @param val   value to be formatted
// @param prec  decimal precision
//
// @return string representation of the double value
std::string to_string_double(double val, const int prec = 2)
{
    std::ostringstream out;
    out << std::fixed << std::setprecision(prec) << val;
    return out.str();
}

// variable used to store jump locations used in the
// time-based assertion macros (ASSERT_TIME, ASSERT_TIMED_BLOCK_START,
// ASSERT_TIMED_BLOCK_END)
static jmp_buf jmp_env;

// This function catches alarms from time-based assertion macros (ASSERT_TIME,
// ASSERT_TIMED_BLOCK_START, ASSERT_TIMED_BLOCK_END)
// @param sig signal number
static void catch_alarm(int sig)
{
    longjmp(jmp_env, 1);
}

// This macro checks whether a function executes within a given time
//
// setjmp is used to mark the line where longjmp from catch_alarm
// will move to when the function call times out.
//
// When val is 0, the signal is initialized and the alarm timer is started.
// The alarm is cancelled if it finishes executing the function before the
// alarm goes off.
//
// If the alarm goes off, the handler catches the alarm and jumps to the line
// that will then set val to 1. This results in a test failure that assigns
// the appropriate error message.
//
// @param fn    function tested
// @param usecs microseconds to wait before function is considered to have
//              timed out
#define ASSERT_TIME(fn, usecs) { \
  const auto val = setjmp(jmp_env); \
  if (val == 0) { \
      signal(SIGALRM, catch_alarm); \
      ualarm((usecs), 0); \
      { fn; }; \
      ualarm(0, 0); \
  } else { \
      GTEST_FATAL_FAILURE_("      " #fn " timed out (> " #usecs \
      " microseconds)"); \
  } }

// This macro indicates the start of a block that checks whether the statements
// it contains executes with a given time. This block must be followed by
// statements that are tested and the ASSERT_TIMED_BLOCK_END macro
//
// The implementation is modeleed after ASSERT_TIME, but splits the implementation
// into a BLOCK_START and BLOCK_END that encloses the statements that are tested.
//
// @param name name of the timed block
// @param usecs microseconds to wait before the statements in the block are
//              considered to have timed out
#define ASSERT_TIMED_BLOCK_START(name, usecs) { \
  const auto val = setjmp(jmp_env); \
  if (val == 1) {\
    GTEST_FATAL_FAILURE_("      " #name " timed out (>" #usecs \
                         " microseconds)"); \
  } else { \
      signal(SIGALRM, catch_alarm); \
      ualarm((usecs), 0); \
  } }

// This macro indicates the end of the timed block that works with the
// ASSERT_TIMED_BLOCK_START macro
#define ASSERT_TIMED_BLOCK_END() { \
   ualarm(0, 0); \
  }

// This macro checks if the output of an executable program matches an expected
// output.
//
// @param prog_name name of the executable file
// @param input     keyboard input sent to the program
// @param output    expected output of the program
#define ASSERT_MAIN_OUTPUT_EQ(prog_name, input, output) \
  if ( access( prog_name, F_OK ) == -1 ) { \
    GTEST_FATAL_FAILURE_("      cannot test '" prog_name "': no such file"); \
  } \
  ASSERT_EQ(main_output(prog_name, input), output);

#define ASSERT_MAIN_OUTPUT_THAT(prog_name, input, matcher) \
  if ( access( prog_name, F_OK ) == -1 ) { \
    GTEST_FATAL_FAILURE_("      cannot test '" prog_name "': no such file"); \
  } \
  ASSERT_THAT(main_output(prog_name, input), matcher);
