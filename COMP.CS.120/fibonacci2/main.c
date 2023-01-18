#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

int main(int argc, char *argv[])
{
  char *fibonacci = fib_jono_mj(atoi(argv[1]));
  printf("%s\n", fibonacci);
  free(fibonacci);
  return 0;
}
