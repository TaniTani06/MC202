#include <stdio.h>

int main(){ //nomes com espaço

    char* pessoas[1000] = {0}, celebridades[1000] = {0};
    char p_1[50], z[9], p_2[50];
    int a = 0;

    while (scanf("%s %s %s", &p_1, &z, &p_2)){ //recebe a linha
        pessoas[0] = p_1;
        pessoas[1] = p_2;
        for(int i=0; i < 1000; i++){ //compara se p_1 pertence a pessoas
            if (pessoas[i] == 0){
                pessoas[i] = p_1;
                break;
            }
            else{
                if (pessoas[i] == p_1){
                    break;
                }
            }
        }
        for(int j=0; j < 1000; j++){ //compara se p_2 pertence a pessoas
            if (pessoas[j] == 0){
                pessoas[j] = p_2;
                break;
            }
            else{
                if (pessoas[j] == p_2){
                    break;
                }
            }
        }
    }
    while(pessoas[a]){
        printf("%s", pessoas[a]);
        a++;
    }
}