#include <stdio.h>

void f1() {
  printf("f1 in mod1\n");
#ifdef __PIC__
  printf("__PIC__ defined\n");
#endif
}
