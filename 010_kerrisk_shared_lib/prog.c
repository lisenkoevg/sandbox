#include <stdio.h>

extern void f1();
extern void f2();

int main() {
  printf("main\n");
  f1();
  f2();
}
