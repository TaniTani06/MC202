#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "sublist.h"

int main(void){
    char op, st;
    int ini, fim, pos, data;
    lista* A;
    lista* new_A;

    A = cria();

    scanf("A = {%d", &data);
    adiciona(A, data);
    scanf("%c", &st);

    while(st == ','){
        scanf(" %d", &data);
        adiciona(A, data);
        scanf("%c", &st);
    }

    scanf("\n");

    while (1){
        scanf("%c ", &op);

        if(op == 's'){
            scanf("A[%d..%d]\n", &ini, &fim);
            new_A = extrair(A, ini, fim);
            
            libera(A);
            A = new_A;
            
            imprimir(A);
        }
        
        else if (op == '+'){
            scanf("A[%d..%d] %d\n", &ini, &fim, &pos);

            new_A = extrair(A, ini, fim);
            inserir(A, new_A, pos);

            imprimir (A);
        }

        else if (op == 'f'){
            libera(A);
            return 0;
        }

        else{
            printf("Invalid command: %c\n", op);
            libera(A);
            return 1;
        }
    }
}