#ifndef YKKOSVALIT_H_INCLUDED
#define YKKOSVALIT_H_INCLUDED

struct UintPari
{
    unsigned int x;
    unsigned int y;
};

typedef struct UintPari UintPari;

UintPari ykkosValit(const char *syoteNimi, const char *tulosNimi);

#endif
