#include <stdio.h>
#include "kolmijako.h"

int main(void)
{
  int t[7] = {1, 7, 4, 5, 2, 8, 9};
  int x = 0;  /* Saa arvon pienet1 osoittimen kautta. */
  int y = 0;  /* Saa arvon pienet2 osoittimen kautta. */
  /* IntPari-olio ip saa arvot pienet1 ja pienet2 paluuarvona. */
  IntPari ip = kolmijako(7, t, 4, 1, &x, &y);
  int i = 0;
  /* Tulostetaan kummallakin tavalla saadut arvot pienet1 ja pienet2. */
  printf("pienet1: %d ja %d\npienet2: %d ja %d\n", x, ip.x, y, ip.y);
  for(i = 0; i < 7; ++i)
  { /* Tarkistetaan järjestyksen laillisuus jakoalkioiden 2 ja 7 suhteen. */
    if(((i < x) && (t[i] >= 2)) || ((i < y) && (t[i] >= 7)))
    {
      printf("Alkioiden järjestys laiton\n");
      break;
    }
  }
  return 0;
}

