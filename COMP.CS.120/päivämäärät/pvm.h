#ifndef PVM_H_INCLUDED
#define PVM_H_INCLUDED


struct Pvm
{
    int pv;
    int kk;
    int vuosi;
    char vk_pv[3];
};

typedef struct Pvm Pvm;

Pvm *kasvataPvm(Pvm *pvm);

unsigned int pvmEro(const Pvm *a, const Pvm *b);

void tulostaPvm(Pvm *pvm);



#endif
