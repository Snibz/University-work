#ifndef KOLMIJAKO_H_INCLUDED
#define KOLMIJAKO_H_INCLUDED

struct IntPari
{
    int x;
    int y;
};

typedef struct IntPari IntPari;

IntPari kolmijako(unsigned int n, int t[], int vipu1, int vipu2,
                  int *p1, int *p2);



#endif
