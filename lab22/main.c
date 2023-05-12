#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "playlist.h"


int main(void){
    int n;
    char op[10];
    char musica[101];
    lista* playlist = cria();


    scanf("%d\n", &n);
    while(n != 0){
        for (int i = n; i > 0; i--){
            scanf("%s", op);

            if (strcmp(op, "insere") == 0){
                scanf("%[^\n] ", musica);
                insere(playlist, musica);
            }

            else if (strcmp(op, "remove") == 0){
                scanf("%[^\n] ", musica);
                tira(playlist, musica);
            }

            else if (strcmp(op, "toca") == 0){
                toca(playlist);
            }

            else if (strcmp(op, "volta") == 0){
                volta(playlist);
            }

            else if (strcmp(op, "final") == 0){
                p_fim(playlist);
            }

            else if (strcmp(op, "inverte") == 0){
                inverte(playlist);
            }

            else{
                printf("Errou! %s não é um comando válido.\n", op);
                libera(playlist);
                return 1;
            }
        }
        libera(playlist);
        playlist = cria();
        scanf("%d\n", &n);
    }
    libera(playlist);
}