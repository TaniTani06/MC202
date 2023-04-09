#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void){
    char frase[120];
    int continua = scanf("%[^\n] ", frase);
    char pessoas[1001][51];
    char pessoa_1[51], pessoa_2[51];
    int conhecimento[1001][1001];
    int i = 0, p, q, k, l, m;

    while (continua == 1){
        char* pos = strstr(frase, " conhece ");
        int loc = pos - frase;                          //local do " conhece " na linha

        memset(pessoa_1, 0, 51);                        //"limpa" as strings
        memset(pessoa_2, 0, 51);

        strncpy(pessoa_1, frase, loc);
        pessoa_1[loc] = '\0';
        strcpy(pessoa_2, frase+loc+9);

        for (p=0; p<1001; p++){                     //verifica se "pessoa_1" está na matriz, e adiciona se não estiver
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

        for (q=0; q<1001; q++){                     //verifica se "pessoa_2" está na matriz e adiciona se não estiver
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

        conhecimento[p][q] = 1;                    //registra que pessoas[p] conhece pessoas[q]
        
        i++;
        continua = scanf("%[^\n] ", frase);
    }
    
    for (k=0; k<q+1; k++){
        for (l=0; l<q+1; l++){
            if (conhecimento[k][l] == 1){           //verifica se há "1" na linha
                break;
            }
        }
        if (conhecimento[k][l] == 0){               //ao sair do loop interno, caso ele seja concluído, verficamos a coluna
            for (m=0; m<q-1; m++){
                if (conhecimento[m][k] == 0){
                    break;
                }
            }
            if (conhecimento[m][k] == 1){
                printf("%s e' celebridade.\n", pessoas[k]);
                return 0;
            }
        }
    }

    printf("Nao ha' celebridade.\n");
    return 0;
}