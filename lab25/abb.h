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

    struct node* pai;
    struct node* L;
    struct node* R;
};

typedef struct node node;

typedef struct{
    node* raiz;
}abb;



abb* cria();
void libera(abb* A);

int inserir(abb* A, int k, char* nome, float pontos);
int subs(abb* A, node* u, node* v);
int remover(abb* A, int k);

node* buscar(node* raiz, int k);
node* max(node* raiz);
node* min(node* raiz);

node* sucessor(node* raiz, int k);
node* predecessor(node* raiz, int k);

int intervalo(abb* A, int x, int y);

#endif