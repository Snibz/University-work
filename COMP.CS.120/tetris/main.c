#include <stdio.h>
/* Muista esitellä paivita-funktio otsaketiedostossa tetris.h */
#include "tetris.h"

/* Alla määritetään 2-ulotteinen 20x10-kokoinen staattinen merkkitaulukko,
   jossa täynnä olevat ruudut on merkitty merkillä 'x'. Kukin 10-alkioinen
   alitaulukko alustetaan merkkijonolla (jonka loppumerkki leikkautuu pois). */
char ruudukko[20][10] = {"          ",  /* Rivi 0: ylin rivi.                */
                         "  x   x   ",  /* Rivi 1: toiseksi ylin rivi.       */
                         " xx   xxx ",  /* ...ja niin edelleen...            */
                         "xxx xxxxxx",
                         "xxxxxxxxxx",  /* Rivi 4: täynnä.                   */
                         "xxxxxxxxxx",  /* Rivi 5: täynnä.                   */
                         "xxxxxx xxx",
                         "xxxxxxx xx",
                         "x xxxxxxxx",
                         "xxx xxx xx",
                         "xxxxxx xxx",
                         "x xx xxx x",
                         "xxxxxxxxx ",
                         "xxx xxx xx",
                         "xxxxx xx x",
                         " xxxxxxxxx",
                         "xxx xxx xx",
                         "x xxxx xxx",
                         "xxxxx xxxx",  /* Rivi 18: toiseksi alin rivi.      */
                         "xxxxxxxx x"}; /* Rivi 19: alin rivi.               */

int main(void)
{
  int i = 0;
  paivita(ruudukko);       /* Poistetaan tyhjät rivit. */
  for(i = 0; i < 20; ++i)  /* Tulostetaan ruudukko.    */
  {
    printf("%.10s\n", ruudukko[i]); /* Tulostetaan 1 rivi eli 10 merkkiä. */
  }
  return 0;
}
