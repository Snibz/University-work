#ifndef MURTOLUKU_UNIQUE
#define MURTOLUKU_UNIQUE


struct Murtoluku
{
    int os;
    int nim;
};

typedef struct Murtoluku Murtoluku;

Murtoluku supistettuML(int os, int nim);

Murtoluku lisaaML(Murtoluku a, Murtoluku b);

Murtoluku vahennaML(Murtoluku a, Murtoluku b);

Murtoluku kerroML(Murtoluku a, Murtoluku b);

Murtoluku jaaML(Murtoluku a, Murtoluku b);

void tulostaML(Murtoluku ml);

int syti(int a, int b);




#endif
