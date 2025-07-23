#include <windows.h>
#include <fstream>

using std::ofstream;
using std::endl;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
  ofstream log("1.log");
  MessageBox(NULL, TEXT("Hello"), TEXT("HelloMsg"), MB_OK | MB_YESNO);
  log << "1" << endl;
  return 0;
}
