
CXXFLAGS = -std=c++20 -Wall -Wfatal-errors -Werror -Wextra
# LDFLAGS = -Wl,--no-undefined -Wl,--fatal-warnings

prog = http_ssl_async_get

all: $(prog).exe

$(prog).exe: $(prog).o
	g++ $(CXXFLAGS) $(LDFLAGS) $< -o $@ -lws2_32 -lssl -lcrypto -lboost_thread-mt

$(prog).o: $(prog).cpp
	g++ $(CXXFLAGS) $< -c -o $@
