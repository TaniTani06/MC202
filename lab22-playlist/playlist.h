#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


#ifndef PLAYLIST_H
#define PLAYLIST_H

struct node{
    char musica[101];
    struct node* next;
    struct node* prev;
};

typedef struct node node;

typedef struct{
    node* inicio;
    node* cursor;
    node* fim;
}lista;

lista* cria();

void insere(lista* L, char* mus);
int tira(lista* L, char* mus);

void toca(lista* L);
void volta(lista* L);
void p_fim(lista* L);
void inverte(lista* L);

void libera(lista* L);

#endif