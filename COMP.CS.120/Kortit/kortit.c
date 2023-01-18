#include <stdlib.h>
#include <stdio.h>
#include "kortit.h"


const char *MAIDEN_NIMET[MAA_LKM +1] =
{
    "", "Hertta", "Ruutu", "Risti", "Pata"
};

const char *KORTTIEN_NIMET[MAA_KOKO + 1] =
{
    "", "ässä", "kakkonen", "kolmonen", "nelonen", "viitonen", "kuutonen",
     "seiska", "kasi", "ysi", "kymppi", "jätkä", "rouva", "kunkku"
};

void tulostaKortti(Kortti kortti)
{
    int maa = kortti.maa;
    int arvo = kortti.arvo;

    const char *maanimi = MAIDEN_NIMET[maa];
    const char *arvonimi = KORTTIEN_NIMET[arvo];
    printf("%s%s", maanimi, arvonimi);
}


void tulostaKorttiOs(const Kortti *korttiOs)
{
    int maa = korttiOs->maa;
    int arvo = korttiOs->arvo;

    const char *maanimi = MAIDEN_NIMET[maa];
    const char *arvonimi = KORTTIEN_NIMET[arvo];
    printf("%s%s", maanimi, arvonimi);
}
