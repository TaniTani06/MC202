#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#ifndef HEAP_H
#define HEAP_H

typedef struct par{
    unsigned ts;
    unsigned key;
    int prio;
}par;

typedef struct heap{
    par* V;
    int cap;
    int size;
}heap;


heap* cria(int n);
par min(par *V);
void min_heapfy(heap *H, int pos);
void inserir(heap *H, par p);
void rem_min(heap *H);
void libera(heap *H);


#endif