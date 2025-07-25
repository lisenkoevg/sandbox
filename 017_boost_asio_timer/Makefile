CXXFLAGS = -std=c++20 -Wall -Wfatal-errors -Werror -Wextra

all: timer.exe

timer.exe: timer.cpp
	g++ $(CXXFLAGS) $< -o $@ -lws2_32
