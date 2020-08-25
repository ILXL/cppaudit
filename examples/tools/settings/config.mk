## Unittest name
UTNAME		:= unittest.cc
# Flags added to compilation step
COMPILE_FLAGS		:= -lm -lX11 -lpthread
# Flags added to unittest compilation step
UT_COMPILE_FLAGS	:= -lm -lX11 -lpthread
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS      		:=
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       		:=
# File containing main (e.g., main.cpp)
DRIVER        		:= main.cc
# Expected name of executable file
EXEC_FILE      		:= main
