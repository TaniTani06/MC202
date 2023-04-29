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

int a(elemento* vetor, int tamanho, int m, int n, int x){
    for (int i = 0; i < tamanho; i++){
        if (vetor[i].linha == m){
            if (vetor[i].coluna == n){
                vetor[i].valor = x;                //atualiza o valor do elemento [i,j], se existir
                return 0;
            }
        }
    }

    for (int i = 0; i < tamanho; i++){
        if (vetor[i].valor == 0){                  //se o elemento [i,j] não existir,
            vetor[i].linha = m;                    //e houver elemento vazio, é adicionado o elemento e suas coordenadas
            vetor[i].coluna = n;
            vetor[i].valor = x;
            return 0;
        }
    }

    printf("O VC esta' cheio.")
    return 0;
}

int r(elemento* vetor, int tamanho, int m, int n){ 
    for (int i = 0; i < tamanho; i++){
        if (vetor[i].linha == m){
            if (vetor[i].coluna == n){                              //procura o elemento no vetor pelos suas coordenadas
                printf("M[%d][%d] == %d\n", m, n, vetor[i].valor);  //imprime seu valor caso encontre
                return 0;
            }
        }
    }

    printf("M[%d][%d] == 0\n", m, n);                               //imprime 0 caso não encontre
    return 0;
}

int p(elemento* vetor, int tamanho){                //função p, imprime o conteúdo do VC, retorna 1(falha) ou 0 (sucesso);
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

r(VC, k, 2, 2);

r(VC, k, 5, 5);

}

//encontrar uma forma de definir qual função é chamada (possivelmente comparando o elemento 0 da string com a e r)
//depois, usar sscanf para retirar a coordenada i, j do elemento (e o valor x a ser subtituido no caso da função a)