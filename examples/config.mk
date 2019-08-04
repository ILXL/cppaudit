# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS       := algebra.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       := algebra.cpp
# File containing main
DRIVER        := restaurant.cpp
# Expected name of executable file
EXECFILE      := restaurant
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard
