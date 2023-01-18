#include <stdio.h>
#include "genhaku.h"

int main(void)
{
  int ix[10] = {4, 1, 0, 8, 2, 9, 0, 8, 2, 9};
  int iy[4] = {0, 8, 2, 9};
  int iz[4] = {0, 9, 2, 8};
  short sx[10] = {4, 1, 0, 8, 2, 9, 0, 8, 2, 9};
  short sy[4] = {0, 8, 2, 9};
  short sz[4] = {0, 9, 2, 9};
  typedef unsigned long ulong;
/*
  printf("%lu\n", (ulong) etsi(sx, 10, sz, 4, sizeof(short)));

  return 0;
*/




  printf("%lu %lu\n", (ulong) etsi(ix, 10, iy, 4, sizeof(int)),
                      (ulong) etsi(ix, 10, iz, 4, sizeof(int)));
  printf("%lu %lu\n", (ulong) etsi(sx, 10, sy, 4, sizeof(short)),
                      (ulong) etsi(sx, 10, sz, 4, sizeof(short)));
  return 0;

}
