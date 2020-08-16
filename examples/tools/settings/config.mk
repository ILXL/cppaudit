# Compiler
CC					:= clang++
# Flags added to compilation step
COMPILE_FLAGS		:= 
# Flags added to unittest compilation step
UT_COMPILE_FLAGS	:=
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS      		:= algebra.hpp
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       		:= algebra.cpp
# File containing main
DRIVER        		:= restaurant.cpp
# Expected name of executable file
EXEC_FILE      		:= main
#CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard
