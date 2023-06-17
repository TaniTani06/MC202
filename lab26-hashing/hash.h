#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#ifndef HASH_H
#define HASH_H

typedef struct elem{
    char str[251];                          //cadeia a ser armazenada
    int ts;                                 //timestamp do elemento
}elem;


typedef struct table{
    elem* data;
    int size;
}table;



unsigned long djb2(unsigned char *str);

int h1(unsigned long k, int m);
int h2(unsigned long k, int tamanho);

elem* busca(table* T, char* str);
table* cria(int tamanho);
int insert(table* T, char* str, int ts);
void remover(table* T, char* str);
void delete(table* T);

#endif