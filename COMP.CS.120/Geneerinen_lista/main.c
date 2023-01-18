#include <stdio.h>
#include "lista.h"

static void tulostaInt(FILE *virta, const void *arvo)
{ /* Tulostaa osoittimen arvo osoittaman int-arvon tulostevirtaan virta. */
  const int *intOsoitin = arvo;
  fprintf(virta, "%d", *intOsoitin);
}

int main(void)
{
  int i = 0;
  int arvoja[5] = {2, 8, 1, 7, 4};
  Lista *ll = ll_luo(sizeof(int), tulostaInt); /* Alkion koko: sizeof(int). */
  for(i = 0; i < 5; ++i)
  { /* Välitetään arvot arvoja[i] osoittimien välityksellä. */
    ll_lisaaEteen(ll, &arvoja[i]);
  }
  ll_tulosta(ll, stdout);
  for(i = 0; i < 5; ++i)
  { /* Välitetään arvo i osoittimen välityksellä. */
    ll_lisaaEteen(ll, &i);
  }
  ll_tulosta(ll, stdout);
  ll_tuhoa(ll);
  return 0;
}
