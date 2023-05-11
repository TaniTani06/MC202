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

        if (strcmp(op, "insere")){
            scanf("%[^\n] ", musica);
            insere(playlist, musica);
        }

        else if (strcmp(op, "remove")){

        }

        else if (strcmp(op, "toca")){

        }

        else if (strcmp(op, "volta")){

        }

        else if (strcmp(op, "final")){

        }

        else if (strcmp(op, "inverte")){

        }

        else{
            printf("Errou! %s não é um comando válido.\n", op);
            libera(playlist);
            return 1;
        }
    }
}