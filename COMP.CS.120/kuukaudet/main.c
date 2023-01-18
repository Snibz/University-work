#include <stdio.h>
#include "kuukaudet.h"


int main(void)
{

    printf("Helmikuu 2016: %d p‰iv‰‰\n", kkPituus("Helmikuu", 2016));
    printf("Helmikuu 2100: %d p‰iv‰‰\n", kkPituus("helmikuu", 2100));
    printf("Helmi kuu 2100: %d p‰iv‰‰\n", kkPituus("helmi kuu", 2100));

    printf("Hein‰kuu 2016: %d p‰iv‰‰\n", kkPituus("hein‰kuu", 2016));
}
