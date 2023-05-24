#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#ifndef RECON_H
#define RECON_H

struct node{
    char data;
    struct node* L;
    struct node* R;
};

typedef struct node node;

struct fila{
    node* F[100];
    int posi;
    int posf;
    int empty;
};

typedef struct fila fila;

node* cria(char raiz);
void libera(node* arv);

int adiciona(node* arv, char data, char* em);
int pos(node* arv);
int larg(node* arv);

void enq(fila Q, node* arv);
node* dequeue (fila Q);

#endif