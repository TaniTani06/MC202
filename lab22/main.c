#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "playlist.h"


int main(void){
    char op[10];
    char musica[101];
    lista* playlist = cria();



    while(1){
        scanf("%s", op);

        if (strcmp(op, "insere") == 0){
            scanf("%[^\n] ", musica);
            insere(playlist, musica);
        }

        else if (strcmp(op, "remove") == 0){

        }

        else if (strcmp(op, "toca") == 0){

        }

        else if (strcmp(op, "volta") == 0){

        }

        else if (strcmp(op, "final") == 0){

        }

        else if (strcmp(op, "inverte") == 0){

        }

        else{
            printf("Errou! %s não é um comando válido.\n", op);
            libera(playlist);
            return 1;
        }
    }
}