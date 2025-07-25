
CXXFLAGS = -std=c++20 -Wall -Wfatal-errors -Werror -Wextra

prog = http_get

all: $(prog).exe

$(prog).exe: $(prog).o
	g++ $(CXXFLAGS) $< -o $@ -lws2_32

$(prog).o: $(prog).cpp
	g++ $(CXXFLAGS) $< -c -o $@
