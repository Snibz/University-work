#include <stdio.h>
#include "lista.h"

static void dl_tulostaTakaperin(DblLista *lista)
{
  size_t i;
  printf("Lista takaperin:");
  for(i = lista->n; i > 0; --i)
  {
    printf(" %.1f", dl_alkio(lista, i-1));
  }
  printf("\n");
}

int main(void)
{
  DblLista *lista = dl_luo();
  size_t i = 0;
  for(i = 1; i <= 10; ++i)
  { /* Lisätään arvoja vaihteleviin kohtiin. */
    size_t j = (i*i/3) % (i+1);
    printf("Lisätään arvo %.1f indeksin %lu eteen\n", i*1.7, (unsigned long) j);
    dl_lisaa(lista, j, i*1.7);
    dl_tulosta(lista);
  }
  printf("Koko: %lu\n", (unsigned long) lista->n);
  dl_tulostaTakaperin(lista);
  for(i = 1; i <= 3; ++i)
  { /* Poistetaan arvoja vaihtelevista kohdista. */
    size_t j = (i*29) % lista->n;
    printf("Poistetaan indeksin %lu alkio\n", (unsigned long) j);
    dl_poista(lista, j);
    dl_tulosta(lista);
  }
  dl_tuhoa(lista);
  return 0;
}
