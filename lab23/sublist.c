#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "sublist.h"


//cria uma lista vazia, com sentinelas no início e fim
lista* cria(){
    lista* L = malloc(sizeof(lista));
    if (L == NULL){
        return NULL;
    }

    node* n = malloc(sizeof(node));
    if (n == NULL){
        return NULL;
    }

    L->inicio = n;

    n = malloc(sizeof(node));

    if (n == NULL){
        return NULL;
    }

    L->fim = n;

    L->inicio->prev = NULL;
    L->inicio->next = L->fim;
    L->fim->prev = L->inicio;
    L->fim->next = NULL;

    return L;
}
