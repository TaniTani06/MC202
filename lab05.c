#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int linha;
    int coluna;
    int valor;
} elemento;

elemento *v_alloc(int n){
    elemento *p = (elemento*) malloc(n * sizeof(elemento));
    return p;

}

int p(elemento* vetor, int tamanho){              //função p, imprime o conteúdo do VC, retorna 1(falha) ou 0 (sucesso);
    printf("VC: ");
    
    for (int i = 0; i < tamanho; i++){
    printf("(%d,%d,%d) ", vetor[i].linha, vetor[i].coluna, vetor[i].valor);
    }
    
    printf("\n");
    return 0;
}

int main(){

int m, n, k;
char str[15];

scanf("%d %d\n", &m, &n);
scanf ("%d\n", &k);

elemento *VC = v_alloc(m+n);

for (int i = 0; i < k; i++){
    scanf("[%d,%d] %d\n", &VC[i].linha, &VC[i].coluna, &VC[i].valor);
}

p(VC, k);

}