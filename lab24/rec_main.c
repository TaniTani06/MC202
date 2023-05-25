#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "recon.h"

int main(void){
    char em[100];
    char pre[100];
    int st = scanf("%s %s", pre, em);
    node* arvore;

    while (st == 2){
        arvore = cria(pre[0]);

        for (int i = 1; i < strlen(pre); i++){
            adiciona(arvore, pre[i], em);
        }

        pos(arvore);

        printf(" ");
        larg(arvore);
        printf("\n");

        libera(arvore);

        st = scanf("%s %s", pre, em);
        
        if (st == -2){
            break;
        }
    }


}