#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>

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
    int h = h1(djb2((unsigned char*)str), T->size);
    int i = 1;
    elem* p = &T->data[h];

    while(T->data[h].ts != -1){
        if(strcmp(T->data[h].str, str) == 0){
            return p;
        }
        h = (h1(djb2((unsigned char*)str), T->size) + i*h2(djb2((unsigned char*)str), T->size))%T->size;
        i++;
        p = &T->data[h];
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
    
    int h = h1(djb2((unsigned char*)str), T->size);
    int i = 1;

    //enquanto a posição estiver ocupada, atualiza h com o hashing duplo
    while(T->data[h].ts >= 0){
        h = (h1(djb2((unsigned char*)str), T->size) + i*h2(djb2((unsigned char*)str), T->size))%T->size;
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
void remover(table* T, char* str){
    elem* p = busca(T, str);

    if(p == NULL){
        return;
    }

    strcpy(p->str, "\0");
    p->ts = -6;
}


void delete(table* T){
    free(T->data);
    free(T);
}


/*Verifica se o número inteiro x é primo*/
unsigned first_prime(unsigned m) {
    if (m == 0 || m == 1){
        return 2;
    }
    if (m == 2 || m == 3){
        return m;
    }
    if (m%2 == 0){
        m += 1;
    }

    while (m) {
        int i=0, lim = (int)sqrt(m);

        if (m%3){
            for (i=6; i<=lim; i+=6){
                if(m%(i+1) == 0 || m%(i-1) == 0){
                    break;
                }
            }
        }

        if(i>lim+1){
            break;
        }
        m+=2;
    }
    return m;
}
