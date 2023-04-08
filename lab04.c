#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void){
    char frase[120];
    int continua = scanf("%[^\n] ", frase);
    char pessoas[1001][51];
    char pessoa_1[51], pessoa_2[51];
    int i = 0;

    while (continua == 1){
        char* pos = strstr(frase, " conhece ");
        int loc = pos - frase;                          //local do " conhece " na linha
        /*printf("%ld\n", loc);*/

        memset(pessoa_1, 0, 51);                        //"limpa" as strings
        memset(pessoa_2, 0, 51);

        strncpy(pessoa_1, frase, loc);
        pessoa_1[loc] = '\0';
        strcpy(pessoa_2, frase+loc+9);

        for (int p=0; p<1001; p++){
            if (strcmp(pessoas[p], pessoa_1) == 0){
                break;
            }
            else{
                if (pessoas[p][1] == 0){
                    strcpy(pessoas[p], pessoa_1);
                    break;
                }
            }
        }

        for (int q=0; q<1001; q++){
            if (strcmp(pessoas[q], pessoa_2) == 0){
                break;
            }
            else{
                if (pessoas[q][1] == 0){
                    strcpy(pessoas[q], pessoa_2);
                    break;
                }
            }
        }

        i++;
        continua = scanf("%[^\n] ", frase);
    }
    for (int j=0; j<7; j++){
        printf("%s\n", pessoas[j]);
    }
    return 0;
}