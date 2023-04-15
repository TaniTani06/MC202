#include<stdio.h>

typedef struct{
    int linha;
    int coluna;
    int valor;
} vetorc;


int main(){

int m, n, k;

scanf("%d %d", m, n);
scanf ("%d", k);

struct VC[m+n];

for (int i = 0; i < k; i++){
    scanf("[%d,%d] %d", VC[i].linha, VC[i].coluna, VC[i].valor);
}

for (int i = 0; i < k; i++){
    printf("(%d,%d,%d)\n", VC[i].linha, VC[i].coluna, VC[i].valor);
}
}