#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#ifndef ABB_H
#define ABB_H

struct node{
    int key;
    char* nome;
    float pontos;

    struct node* L;
    struct node* R;
};
typedef struct node node;

node* cria();
void libera(node* raiz);

int inserir(node* raiz, int k, char* nome, float pontos);
int remover(node* raiz, int k);
int buscar(node* raiz, int k);

int max(node* arv);
int min(node* arv);

int sucessor(node* arv, int k);
int predecessor(node* arv, int k);

int intervalo(node* arv, int x, int y);

#endif