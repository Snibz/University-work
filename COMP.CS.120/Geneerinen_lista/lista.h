#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stddef.h>

struct Solmu
{
  void *data;
  struct Solmu *seur;
};

typedef struct Solmu Solmu;

Solmu * s_luo(const void *data, size_t dataKoko, Solmu *seur);

struct Lista
{
  size_t n;
  Solmu *paa;
  void (*tulostaArvo)(FILE *virta, const void *arvo);
  size_t dataKoko;
};

typedef struct Lista Lista;

Lista * ll_luo(size_t dataKoko, void (*tulostaArvo)(FILE *virta, const void *arvo));

void ll_tuhoa(Lista *ll);

Solmu * ll_lisaaEteen(Lista *ll, const void *arvo);

void ll_poistaEdesta(Lista *ll);

void ll_tulosta(const Lista *lista, FILE *virta);

#endif
