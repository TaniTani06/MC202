#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "playlist.h"


//cria uma playlist vazia, com sentinelas no início e fim e cursor no início
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
    
    L->cursor = malloc(sizeof(node));
    L->cursor->prev = L->inicio;
    L->cursor->next = L->fim;

    return L;
}


/*adiciona uma música após a posição atual do cursor
O cursor->prev aponta para a música atual da playlist
O cursor->next aponta para a música seguinte
*/
void insere(lista* L, char* mus){
        if (L->cursor->prev == L->inicio){
            node* n = malloc(sizeof(node));

            strcpy(n->musica, mus);
            n->next = L->cursor->next;
            n->prev = L->cursor->prev;

            L->cursor->next->prev = n;
            L->cursor->prev->next = n;
            L->cursor->prev = n;
        }
        else{
            node* n = malloc(sizeof(node));

            strcpy(n->musica, mus);
            n->next = L->cursor->next;
            n->prev = L->cursor->prev;

            L->cursor->next->prev = n;
            L->cursor->prev->next = n;
            L->cursor->next = n;
        }
}



void tira(lista* L, char* mus);


/*Imprime a música atual (cursor->prev)
Move o cursor para a próxima música, se houver
*/
void toca(lista* L){
    printf("%s\n", L->cursor->prev->musica);

    if(L->cursor->next != L->fim){
        L->cursor->prev = L->cursor->next;
        L->cursor->next = L->cursor->next->next;
    }
}



void volta(lista* L);



void p_fim(lista* L);



void inverte(lista* L);

void libera(lista* L){
    node* p = L->inicio;

    while (p) {
    L->inicio = L->inicio->next;
    free(p);
    p = L->inicio;
    }

    free(L->cursor);
    free(L);
}