#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void){
    char frase[120];
    int continua = scanf("%[^\n] ", frase);
    char pessoas[1001][51];
    int i = 0;

    while (continua == 1){
        char* pos = strstr(frase, " conhece ");
        int loc = pos - frase;                          //local do " conhece " na linha
        /*printf("%ld\n", loc);*/
        
        strncpy(pessoas[i], frase, loc);
        pessoas[i][loc] = '\0';
        i++;

        strcpy(pessoas[i], frase+loc+9);

        printf("%s %s\n", pessoas[i-1], pessoas[i]);

        i++;
        continua = scanf("%[^\n] ", frase);
    }
    for (int j=0; j<7; j++){
        printf("%s\n", pessoas[j]);
    }
    return 0;
}