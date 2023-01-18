#include <stdio.h>
#include <stdlib.h>
#include "kertotaulu.h"

int main(int argc, char *argv[])
{
  uint a = atoi(argv[1]);
  uint b = atoi(argv[2]);
  uint c = atoi(argv[3]);
  uint d = atoi(argv[4]);
  char **kertotaulu = luo_kertotaulu_mjt(a, b, c, d);
  uint i = 0;
  for(i = 0; i <= (d-c+1); ++i)    /* Rivit */
  {
    printf("%s\n", kertotaulu[i]);
    free(kertotaulu[i]);
  }
  free(kertotaulu);
  return 0;
}
