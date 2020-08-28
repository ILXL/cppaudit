## Unittest name
UTNAME		:= unittest.cc
# Flags added to compilation step
COMPILE_FLAGS		:= -lm -lX11 -lpthread
# Flags added to unittest compilation step
UT_COMPILE_FLAGS	:= -lm -lX11 -lpthread
# Flags added for mac compilation, if different from COMPILE_FLAGS
MAC_COMPILE_FLAGS	:= -lm -I/opt/X11/include -lpthread -lX11 -lstdc++ -I/usr/X11R6/include -L/usr/X11R6/lib
# Flags added for mac unittest compilation step, if different from UT_COMPILE_FLAGS
MAC_UT_COMPILE_FLAGS := -lm -lpthread -lX11 -I/usr/X11R6/include -L/usr/X11R6/lib
# Space-separated list of header files (e.g., algebra.hpp)
HEADERS      		:=
# Space-separated list of implementation files (e.g., algebra.cpp)
IMPLEMS       		:=
# File containing main (e.g., main.cpp)
DRIVER        		:= main.cc
# Expected name of executable file
EXEC_FILE      		:= main
