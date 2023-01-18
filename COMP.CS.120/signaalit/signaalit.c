#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "signaalit.h"

jmp_buf paluuTila;

void hoidaSIGFPE(int s)
{
    signal(SIGFPE, hoidaSIGFPE);
    longjmp(paluuTila, SIGFPE);
}

void hoidaSIGSEGV(int s)
{
    signal(SIGSEGV, hoidaSIGSEGV);
    longjmp(paluuTila, SIGSEGV);
}
