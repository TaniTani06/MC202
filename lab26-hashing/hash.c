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
elem* busca(table T, char* str);
elem* cria(int tamanho);

/*verifica se a cadeia está na tabela, se sim, não faz nada, se não adiciona*/
void insert(table T, char* str, int ts){
    if(busca(T, str)!=NULL){
        return;
    }
    
    int h = h1(djb2(str), T.size);
    int i = 1;

    //enquanto a posição estiver ocupada, atualiza h com o hashing duplo
    while(T.data[h].ts > 0){
        h = (h1(djb2(str), T.size) + i*h2(djb2(str), T.size))%T.size;
        i++;
    }

    strcpy(T.data[h].str, str);
    T.data[h].ts = ts;
}

/**/
void remover(table T, char* str);
void deleta(table T);