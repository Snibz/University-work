#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stddef.h>

struct DblSolmu
{
  double data;
  struct DblSolmu *seur;
};

typedef struct DblSolmu DblSolmu;

DblSolmu * ds_luo(double data, DblSolmu *seur);

struct DblLista
{
  size_t n;
  DblSolmu *paa;
};

typedef struct DblLista DblLista;

DblLista * dl_luo(void);

void dl_tuhoa(DblLista *dl);

DblSolmu * dl_lisaaEteen(DblLista *dl, double arvo);

double dl_poistaEdesta(DblLista *dl);

void dl_tulosta(const DblLista *lista);

/* tbd */
double dl_alkio(const DblLista *lista, size_t i);

DblSolmu * dl_lisaa(DblLista *lista, size_t i, double arvo);

double dl_poista(DblLista *lista, size_t i);


#endif
