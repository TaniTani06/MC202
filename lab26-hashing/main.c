#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>

#include "hash.h"

int main(void){
    char str[251], func[2];
    int n, tamanho, timest = 0;
    table* T = NULL;
    elem* p;

    while(1){
        scanf("%s", func);

        if(strcmp(func, "c")==0){
            scanf(" %d\n", &n);
            tamanho = ((n/0.7)+1);
            tamanho = (int)first_prime(tamanho);
            
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
            remover(T, str);
        }

        else if(strcmp(func, "b") == 0){
            scanf("%*c%[^\n] ", str);
            p = busca(T, str);

            if(p == NULL){
                printf("[%s] nao esta na tabela\n", str);
            }
            else{
                printf("[%s] esta na tabela, timestamp %d\n", str, p->ts);
            }
        }

        else if(strcmp(func, "f") == 0){
            delete(T);
            return 0;
        }

        else{
            printf("Função inválida: %s\n", func);
            delete(T);
            return 1;
        }
    }
}