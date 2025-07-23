# MINGW = c:\\msys64\\mingw64\\bin
lib = sudet.dll

CXXFLAGS = -std=c++20 -Wall -Wfatal-errors -Werror -Wextra
all: $(lib) tester

tester: tester.cpp
	g++ $(CXXFLAGS) $< -L . -l:$(lib) -o $@

$(lib): sudet.cpp sudet.hpp
	g++ $(CXXFLAGS) -shared -fPIC $< -o $@ -lole32 -loleaut32
