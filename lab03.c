#include<stdio.h>

int minimo(int* lista, int n_atend){
    int min = 0;
    for (int i=1; i < n_atend; i++){
        if (lista[i]==0){
            return min;
        }
        else{
            if (lista[i] < lista[min]){
                min = i;
            }
        }
    }
}

int main(){
    int atendentes;
    int clientes;
    int chegada;
    int atendimento;
    int livre[101] = {0};

    scanf("%d %d", &atendentes, &clientes);
    for (int linha=0; linha < atendentes; linha++){
        scanf("%d %d", &chegada, &atendimento);
        livre[linha] = chegada + atendimento;
    }
    
    for (linha = atendentes; linha < clientes){
        scanf("%d %d", &chegada, &clientes);
    }
    
}


