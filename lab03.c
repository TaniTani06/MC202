#include<stdio.h>

int minimo(int* lista, int n_atend);

int main(){
    int atendentes;
    int clientes;
    int chegada;
    int atendimento;
    int espera;
    int mais20;
    int livre[101] = {0};

    mais20 = 0;

    scanf("%d %d", &atendentes, &clientes);
    for (int linha=0; linha <atendentes; linha++){
        scanf("%d %d", &chegada, &atendimento);
        livre[linha] = chegada + atendimento;
    }

    for (int novalinha = atendentes; novalinha < clientes; novalinha++){
        int m = minimo(livre,atendentes);
        scanf("%d %d", &chegada, &atendimento);
        if (chegada < livre[m]){
            espera = livre[m] - chegada;
            if (espera>20){
                mais20++;
            }
            livre[m] += atendimento;
        }
        else{
            livre[m] = chegada + atendimento;
        }
    }

    printf("%d\n", mais20);    
}

int minimo(int* lista, int n_atend){
    int min;
    min = 0;
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
    return min;
}