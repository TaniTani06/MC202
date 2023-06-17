#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "hash.h"

unsigned long djb2(unsigned char *str) {
  unsigned long hash = 5381;
  int c;
  
  while ((c = *str++))
    hash = ((hash << 5) + hash) ^ c; // hash * 33 XOR c
  
  return hash;
}


//------------funções de hashing------------//
int h1(unsigned long k, int m){
    return k%m;
}

int h2(unsigned long k, int m){
    return 1+(k%(m-2));
}


//-------------funções da tabela------------//
elem* busca(table* T, char* str){
    int h = h1(djb2(str), T->size);
    int i = 1;
    elem* p = T->data;

    while(T->data[h].ts != -1){
        if(strcmp(T->data[h].str, str) == 0){
            return p;
        }
        h = (h1(djb2(str), T->size) + i*h2(djb2(str), T->size))%T->size;
        i++;
        p++;
    }

    return NULL;
}


/*aloca memória para a tabela T, seu array de elementos e inicializa os timestamps para -1*/
table* cria(int tamanho){
    table* T = malloc(sizeof(table));
    T->data = malloc(tamanho*sizeof(elem));
    T->size = tamanho;

    for (int i=0; i<tamanho; i++){
        T->data[i].ts = -1;
    }

    return T;
}


/*verifica se a cadeia está na tabela, se sim, não faz nada, se não adiciona*/
int insert(table* T, char* str, int ts){
    if(busca(T, str)!=NULL){
        return 1;
    }
    
    int h = h1(djb2(str), T->size);
    int i = 1;

    //enquanto a posição estiver ocupada, atualiza h com o hashing duplo
    while(T->data[h].ts > 0){
        h = (h1(djb2(str), T->size) + i*h2(djb2(str), T->size))%T->size;
        i++;
        /*if(i == T->size){
            return;
        }*/
    }

    strcpy(T->data[h].str, str);
    T->data[h].ts = ts;
    return 0;
}


/*busca e remove a cadeia, se houver*/
int remove(table* T, char* str){
    elem* p = busca(T, str);

    if(p == NULL){
        return 1;
    }

    strcpy(p->str, "\0");
    p->ts = -6;
    return 0;
}


void delete(table* T){
    free(T->data);
    free(T);
}