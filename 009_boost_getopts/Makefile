all: program

CXXFLAGS = -Wall -Wextra -Werror -Wfatal-errors -O3

program: program.cpp
	g++ ${CXXFLAGS} $^ -o $@ -lboost_program_options
