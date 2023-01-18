#ifndef SIGNAALIT_H_INCLUDED
#define SIGNAALIT_H_INCLUDED

#include <signal.h>
#include <setjmp.h>

extern jmp_buf paluuTila;

void hoidaSIGFPE(int s);

void hoidaSIGSEGV(int s);

#endif
