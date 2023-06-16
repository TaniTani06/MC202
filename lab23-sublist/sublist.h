#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


#ifndef PLAYLIST_H
#define PLAYLIST_H

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node node;

typedef struct{
    node* head;
    node* tail;
}lista;


lista* cria();

void libera(lista* L);
int adiciona(lista* L, int data);
lista* extrair(lista* L, int start, int end);
int inserir(lista* L, lista* new_L, int pos);
void imprimir(lista* L);

#endif