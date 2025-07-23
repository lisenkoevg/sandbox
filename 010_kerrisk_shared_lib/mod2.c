#include <stdio.h>

void f2() {
  printf("f2 in mod2\n");
#ifdef __PIC__
  printf("__PIC__ defined\n");
#endif
}
