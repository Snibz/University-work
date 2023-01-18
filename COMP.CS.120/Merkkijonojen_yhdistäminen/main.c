#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "yhdista.h"

int main(int argc, char *argv[])
{
  int i = 0;
  char *mj = malloc(1);
  mj[0] = '\0';  /* Alussa vain tyhjä merkkijono. */
  for(i = 1; (i+3) <= argc; i += 3)
  { /* Yhdistetään aina 3 seuraavaa mj:n perään. */
    char *tmp = mj;
    mj = yhdista(tmp, argv[i], argv[i+1], argv[i+2], NULL);
    free(tmp); /* Vapautetaan edellinen mj. */
  }
  if((i+2) == argc) /* Jäikö vielä 2 liittämättä? */
  {
    char *tmp = mj;
    mj = yhdista(mj, argv[i], argv[i+1], NULL);
    free(tmp);
  }
  else if((i+1) == argc) /* Jäikö vielä 1 liittämättä? */
  {
    char *tmp = mj;
    mj = yhdista(mj, argv[i], NULL);
    free(tmp);
  }
  printf("Parametrien liitos: %s (pituus: %lu)\n", mj, (unsigned long) strlen(mj));
  free(mj);
  return 0;
}
