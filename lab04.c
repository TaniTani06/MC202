#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void){
    char frase[120] = {0};
    char pessoas[1001][51] = {0};
    char pessoa_1[51] = {0}, pessoa_2[51] = {0};
    int matriz_conhecimento[1001][1001] = {0};
    int celebridade[1001] = {0};
    int conhece[1001] = {0};
    int i = 0;
    int p, q, tamanho;
    int continua = scanf("%[^\n] ", frase);
    

    for (i=0; i<1001; i++){
        pessoas[i][0] = '\0';
    }

    while (continua == 1){
        char* pos = strstr(frase, " conhece ");
        int loc = pos - frase;                          //local do " conhece " na linha

        strncpy(pessoa_1, frase, loc);
        pessoa_1[loc] = '\0';
        strcpy(pessoa_2, frase+loc+9);

        for (p=0; p<1001; p++){                     //verifica se "pessoa_1" está na matriz, e adiciona se não estiver
            if (strcmp(pessoas[p], pessoa_1) == 0){
                break;
            }
            else{
                if (pessoas[p][0] == '\0'){
                    strcpy(pessoas[p], pessoa_1);
                    tamanho = p+1;
                    break;
                }
            }
        }
        
        for (q=0; q<1001; q++){                     //verifica se "pessoa_2" está na matriz e adiciona se não estiver
            if (strcmp(pessoas[q], pessoa_2) == 0){
                break;
            }
            else{
                if (pessoas[q][0] == '\0'){
                    strcpy(pessoas[q], pessoa_2);
                    tamanho = q+1;
                    break;
                }
            }
        }
        
        matriz_conhecimento[p][q] = 1;                    //registra que pessoas[p] conhece pessoas[q]
        
        i++;
        continua = scanf("%[^\n] ", frase);
    }

    
    for (int j = 0; j < tamanho; j++){                  // calcula quantas pessoas conhecem a pessoa j
        for (i = 0; i < tamanho; i++){
            celebridade[j] += matriz_conhecimento[i][j];
        }
    }
    
    for (i = 0; i < tamanho; i++){                      // calcula quantas pessoas a pessoa i conhece, deve ser 0 para ser celeb
        for (int j = 0; j < tamanho; j++){
            conhece[i] += matriz_conhecimento[i][j];
        }
    }
    
    for (i = 0; i < tamanho; i++){
        if (celebridade[i] == tamanho-1){               // se a pessoa conhece todas, exceto ela (tamanho-1)
            if (conhece[i] == 0){                       // se a pessoa n conhece ninguém
                printf("%s e' celebridade.\n", pessoas[i]);
                return 0;
            }
        }
    }


    printf("Nao ha' celebridade.\n");
    return 0;
}