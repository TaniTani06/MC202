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

//typedef struct fila fila;


node* cria(char raiz);
void libera(node* arv);

int adiciona(node* arv, char data, char* em);
void pos(node* arv);
void larg(node* arv);

#endif