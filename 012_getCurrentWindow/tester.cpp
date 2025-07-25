#include <iostream>
#include <fstream>
#include <chrono>
#include <windows.h>

#include "sudet.hpp"

using std::cout;
using std::endl;
using std::ofstream;

int main() {
  ofstream logFile("main.log");
  for (;;) {
    OpenEntityReaderEx();
    ExtractEntityEx();
    CloseEntityReaderEx();
//     cout << h << endl;
#if 0
    const auto now = std::chrono::system_clock::now();
    const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
    logFile << h << " " << std::ctime(&t_c);
    flush(logFile);
    cout << ".";
    flush(cout);
#endif

    Sleep(3000);
  }
}
