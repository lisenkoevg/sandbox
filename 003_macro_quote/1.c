#include <stdio.h>

#define LOG_ROOT "./1"
#define PROG_NAME "nbdkit"

int main() {
  FILE *f = fopen(LOG_ROOT "/" PROG_NAME, "a");
  fclose(f);
}
