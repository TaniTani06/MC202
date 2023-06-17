#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "hash.h"

int main(void){
    char str[251], func;
    int n, tamanho, timest;
    table* T = NULL;
    elem* p;

    while(1){
        scanf("%c", &func);

        if(strcmp(func, "c")==0){
            scanf(" %d\n", &n);
            tamanho = ((n/0.7)+1);
            if(tamanho%2 == 0){
                tamanho++;
            }
            
            if(T!=NULL){
                delete(T);
                T = NULL;
            }

            T = cria(tamanho);
            timest = 0;
        }

        else if(strcmp(func, "i") == 0){
            scanf("%*c%[^\n] ", str);           //ingora o primeiro caracter lido (' ')
            if(insert(T,str,timest) == 0){
                timest++;
            }
        }

        else if(strcmp(func, "r") == 0){
            scanf("%*c%[^\n] ", str);
            remove(T, str);
        }

        else if(strcmp(func, "b") == 0){
            scanf("%*c%[^\n] ", str);
            p = busca(T, str);

            if(p == NULL){
                printf("[%s] nao esta na tabela\n", str);
            }
            else{
                printf("[%s] esta na tabela, timestamp %d\n", str, timest);
            }
        }

        else if(strcmp(func, "f") == 0){
            delete(T);
        }

        else{
            printf("Função inválida!\n");
        }
    }
}




//x = ((n/0.7)+1);