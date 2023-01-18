#ifndef PISTE3D_H_INCLUDED
#define PISTE3D_H_INCLUDED

struct Piste3D
{
    double x;
    double y;
    double z;
};
typedef struct Piste3D Piste3D;

double etaisyys(Piste3D first, Piste3D second);

void tulosta(Piste3D p, int tarkkuus);

#endif
