#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

DblSolmu * ds_luo(double data, DblSolmu *seur)
{
  DblSolmu *ds = malloc(sizeof(DblSolmu));
  ds->data = data;
  ds->seur = seur;
  return ds;
}

DblLista * dl_luo(void)
{
  DblLista *dl = malloc(sizeof(DblLista));
  dl->n = 0;
  dl->paa = NULL;
  return dl;
}

void dl_tuhoa(DblLista *dl)
{
  while(dl->n > 0)
  {
    dl_poistaEdesta(dl);
  }
  free(dl);
}

DblSolmu * dl_lisaaEteen(DblLista *dl, double arvo)
{
  dl->paa = ds_luo(arvo, dl->paa);
  dl->n += 1;
  return dl->paa;
}

double dl_poistaEdesta(DblLista *dl)
{
  double arvo = 0;
  if(dl->n > 0)
  {
    DblSolmu *vanhaPaa = dl->paa;
    arvo = dl->paa->data;
    dl->paa = dl->paa->seur;
    free(vanhaPaa);
    dl->n -= 1;
  }
  return arvo;
}

void dl_tulosta(const DblLista *lista)
{
  DblSolmu *s;
  printf("Lista:");
  for(s = lista->paa; s != NULL; s = s->seur)
  {
    printf(" %.1f", s->data);
  }
  printf("\n");
}

double dl_alkio(const DblLista *lista, size_t i)
{
    /* Returns the value saved in the object of list index i.
       returns 0 if invalid index. */
    int indices_handled = 0;
    int i_found = 0;
    DblSolmu *current = lista->paa;
    double data = 0;


    while(i_found == 0 && indices_handled < lista->n)
    {
        /* We can only directly access the first object in the linked list,
           so we need to keep track which pointer is being handled.
        */
        if(indices_handled == i)
        {
           /* This means the correct object was found */
           data = current->data;
           i_found = 1;
        }
        else
        {
            /* Move forwards in the structure, increase counters */
            current = current->seur;
            indices_handled += 1;
        }
    }

    return data;
}

DblSolmu * dl_lisaa(DblLista *lista, size_t i, double arvo)
{
    /* Creates a new object in front of current list index i, which has value
       arvo in it. If no object with index i exists yet, addage of object will
       happen to the end of the structure. Updates size of structure.
       Returns a pointer to the new object.

       Since the structure is linked in one way only, once an object is added,
       some pointers need to be updated. Since we know the new object is added
       in front of object of index i, then object of index i must be made to
       point to new object, and new object made to point to whatever
       object of index i pointed to before. Here lie possible exceptions.
    */

    /* CURRENT LOGIC WRONG - IT SUPPOSED TO ADD TO THE PRECEDING SLOT,
       NOT THE FOLLOWING
       ALSO REMOVAL SEEMS TO NOT WORK
    */

    int indices_handled = 0;
    DblSolmu *current = lista->paa;
    DblSolmu *previous = NULL; /* Ended here, to follow which was previous,
    not following */
    DblSolmu *new_obj = NULL;
    int operation_complete = 0;

    while(operation_complete == 0 && indices_handled < lista->n)
    {
        /* New object has not yet been created, and the current index is less
        than or equal to last object.
        Do separate checks for other relevant cases below */

        /* So this here loop may handle adding to the beginning of the structure
           or to any in between or directly after the last, provided that the
           structure already exists
        */
        DblSolmu *following = current->seur;

        if(indices_handled == i)
        {
            new_obj = ds_luo(arvo, NULL);
            if(indices_handled == 0)
            {
                /* This here the exception, no previous so new will be head */
                lista->paa = new_obj;
                new_obj->seur = current;
                lista->n += 1;
                operation_complete = 1;
            }
            else
            {
                /* it's gonna be in front of an existing number */
                previous->seur = new_obj;
                new_obj->seur = current;
                lista->n += 1;
                operation_complete = 1;
            }


        }
        indices_handled += 1;
        previous = current;
        current = current->seur;
    }

    if(operation_complete == 0)
    {
        /* While-loop has been exited without doing the addage.
           Either list is empty or the given i does not respond to any existing
           object.
           Loop not necessary.
        */
        if(previous != NULL)
        {
            /* List is not empty - new object will be absolute last */
            DblSolmu *new_obj = ds_luo(arvo, NULL);
            previous->seur = new_obj;

            lista->n += 1;
            operation_complete = 1;
        }
        else
        {
            /* List is completely empty */
            DblSolmu *new_obj = ds_luo(arvo, NULL);
            lista->paa = new_obj;
            lista->n += 1;
            operation_complete = 1;
        }
    }

    return new_obj;
}

double dl_poista(DblLista *lista, size_t i)
{
    /* Removes the object of index i from the list, and returns it's value.
    Returns 0 if invalid i
    */
    int indices_handled = 0;
    double data = 0;
    int operation_complete = 0;
    DblSolmu *current = lista->paa;
    DblSolmu *previous = NULL;

    if(i < 0 || i >= lista->n)
    {
        /* Invalid i */
        return data;
    }
    else
    {
        /* Valid i. */

        while(operation_complete == 0)
        {

            if(indices_handled == i)
            {
                /* It's the current to be removed */
                data = current->data;

                if(i == 0)
                {
                    lista->paa = current->seur;
                    free(current);
                    lista->n -= 1;
                    operation_complete = 1;
                }
                else
                {
                    previous->seur = current->seur;
                    free(current);
                    lista->n -= 1;
                    operation_complete = 1;
                }
            }
            else
            {
                previous = current;
                current = current->seur;
                indices_handled += 1;
            }

        }

    }
    return data;

}
