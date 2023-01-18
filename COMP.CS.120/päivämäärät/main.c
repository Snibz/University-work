#include <stdio.h>
#include "pvm.h"

int main(int argc, char *argv[])
{
  /*
  Pvm a = {28, 2, 1900, "ke"}; /* Keskiviikko 28.2.1900
  Pvm b = {28, 2, 2016, "su"}; /* Sunnuntai 28.2.2016
  Pvm c = {31, 12, 1960, "la"}; /* Lauantai 31.12.1960
  printf("Pvm:n koko: %lu tavua\n", (unsigned long) sizeof(Pvm));
  printf("Päivämäärät ennen kasvattamista:\n");
  tulostaPvm(&a);  /* Parametri: osoitin Pvm-olioon a eli olion a osoite.
  printf("\n");  tulostaPvm(&b);  printf("\n");  tulostaPvm(&c);
  printf("\n");
  printf("Päivämäärät kasvattamisen jälkeen:\n");
  tulostaPvm(kasvataPvm(&a));      /* Ensin kasvattaa ja sitten tulostaa.
  printf("\n");  tulostaPvm(kasvataPvm(&b));  printf("\n");  tulostaPvm(kasvataPvm(&c));
  printf("\n");
  printf("Päivämäärien erot:\n");
  tulostaPvm(&a);  printf(" vs ");  tulostaPvm(&b);  printf(": %u\n", pvmEro(&a, &b));
  tulostaPvm(&b);  printf(" vs ");  tulostaPvm(&c);  printf(": %u\n", pvmEro(&b, &c));
  tulostaPvm(&a);  printf(" vs ");  tulostaPvm(&c);  printf(": %u\n", pvmEro(&a, &c));
  */

  Pvm a = {28, 2, 1900, "ke"}; /* Keskiviikko 28.2.1900 */
  printf("Päivämäärät ennen kasvattamista:\n");
  tulostaPvm(&a);
  printf("\n");
  printf("Päivämäärät kasvattamisen jälkeen:\n");
  tulostaPvm(kasvataPvm(&a));



  return 0;

}
