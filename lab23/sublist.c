#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "sublist.h"



lista* cria(){
    lista* L = malloc(sizeof(lista));
    if (L == NULL){
        return NULL;
    }

    node* n = malloc(sizeof(node));
    if (n == NULL){
        return NULL;
    }

    L->head = n;

    n = malloc(sizeof(node));

    if (n == NULL){
        return NULL;
    }

    L->tail = n;

    L->head->prev = NULL;
    L->head->next = L->tail;
    L->tail->prev = L->head;
    L->tail->next = NULL;

    return L;
}



void libera(lista* L){
    node* p = L->head;

    while (p) {
    L->head = L->head->next;
    free(p);
    p = L->head;
    }

    free(L);
}


int adiciona(lista* L, int data){
    node* p = malloc(sizeof(node));
    if (p == NULL){
        return 0;
    }

    p->data = data;
    
    p->next = L->tail;
    p->prev = L->tail->prev;

    L->tail->prev->next = p;
    L->tail->prev = p;

    return 1;
}



lista* extrair(lista* L, int start, int end){
    int i;
    lista* new_L = cria();

    node* n = malloc(sizeof(node));
    n = L->head->next;

    for (i = 0; i < start; i++){
        n = n->next;
    }

    if (start <= end){
        for (i = start; i <= end; i++){
            adiciona(new_L, n->data);
            n = n->next;
        }
    }

    else if (start > end){
        for (i = start; i >= end; i--){
            adiciona(new_L, n->data);
            n = n->prev;
        }
    }

    return new_L;
}



int inserir(lista* L, lista* new_L, int pos){
    int i;

    node* p = malloc(sizeof(node));
    if (p == NULL){
        return 0;
    }

    p = L->head;

    for (i = 0; i < pos; i++){
        p = p->next;
    }

    new_L->tail->prev->next = p->next;
    p->next->prev = new_L->tail->prev;

    new_L->head->next->prev = p;
    p->next = new_L->head->next;


    new_L->head->next = new_L->tail;
    new_L->tail->prev = new_L->head;

    libera(new_L);

    return 1;
}



void imprimir(lista* L){
    node* p = malloc(sizeof(node));
    p = L->head->next;

    printf("A: { %d", p->data);
    p = p->next;

    while (p != L->tail){
        printf(", %d", p->data);
        p = p->next;
    }

    printf(" }\n");
}