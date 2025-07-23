#include <iostream>
#include <wchar.h>

int main() {
  static int pad = 2;
  wchar_t fmt[30];
  swprintf(fmt, 30, L"%% %dls%%ls", pad);
  wprintf(L"|");
  wprintf(fmt, L"", L"aaa");
  wprintf(L"|\n");
//   std::cout << "|\n";
}
