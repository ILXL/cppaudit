## Unittest name
UTNAME		:= unittest.cc
# Flags added to compilation step
COMPILE_FLAGS		:=
# Flags added to unittest compilation step
UT_COMPILE_FLAGS	:=
# Flags added for mac compilation, if different from COMPILE_FLAGS
MAC_COMPILE_FLAGS	:=
# Flags added for mac unittest compilation step, if different from UT_COMPILE_FLAGS
MAC_UT_COMPILE_FLAGS :=
# Space-separated list of implementation files that should not be style/format
# checked, i.e. library definitions from cpputils.
OTHER_IMPLEMS	:=
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS      		:= math.h
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       		:= math.cc
# File containing main (e.g., main.cpp)
DRIVER        		:= main.cc
# Expected name of executable file
EXEC_FILE      		:= main
# Flags to pass to clang-format, for example, --style=Google. Use quotes around
# multiple flags. Optional.
CLANG_FORMAT_FLAGS	:= "--style=Google"
