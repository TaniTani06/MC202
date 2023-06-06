#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "abb.h"

int main(void){
    int k, pts, x, y;
    char func[18], nome[101];
    abb* A = NULL;

    while (1){
        scanf("%s", func);

        if (strcmp(func, "criar") == 0){
            if (A != NULL){
                libera(A);
            }
            A = cria();
        }

        else if (strcmp(func, "inserir") == 0){
            scanf(" ")
        }

        else if (strcmp(func, "remover") == 0){
            
        }

        else if (strcmp(func, "buscar") == 0){
            
        }

        else if (strcmp(func, "imprimir") == 0){
            
        }

        else if (strcmp(func, "minimo") == 0){
            
        }

        else if (strcmp(func, "maximo") == 0){
            
        }

        else if (strcmp(func, "sucessor") == 0){
            
        }

        else if (strcmp(func, "predecessor") == 0){
            
        }

        else if (strcmp(func, "buscar-intervalo") == 0){
            
        }

        else if (strcmp(func, "terminar") == 0){
            
        }
    }


















}