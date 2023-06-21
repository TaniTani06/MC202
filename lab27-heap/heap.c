#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "heap.h"

/*Aloca memória para um heap e para o vetor de pares associado a ele, com capacidade máxima igual à
próxima potência de 2 maior que n. Retorna NULL se falhar ou o heap H se houver sucesso*/
heap* cria(int n){
    int cap = 1;
    while(cap<n){
        cap *= 2;
    }

    heap *H = malloc(sizeof(heap));
    if (H == NULL){
        return NULL;
    }
    H->V = malloc(cap*sizeof(par));
    if (H->V == NULL){
        return NULL;
    }
    H->cap = cap;
    H->size = 0;

    return H;
}

/*Recupera o mínimo (primeiro elemento).*/
par min(par *V){
    return V[0];
}


/*Troca o pai com o menor filho caso não seja menor que ambos, se for igual, há desempate
pelo timestamp*/
void min_heapfy(heap *H, int pos){
    int menor = pos;
    par x;
    par *V = H->V;
    int L = 2*pos +1;
    int R = 2*pos +2;

    if (L <= H->size){
        if (V[L].prio < V[menor].prio){
            menor = L;
        }
        else if (V[L].prio == V[menor].prio){
            if (V[L].ts < V[menor].ts){
                menor = L;
            }
        }
    }

    if (R <= H->size){
        if (V[R].prio < V[menor].prio){
            menor = R;
        }
        else if (V[R].prio == V[menor].prio){
            if (V[R].ts < V[menor].ts){
                menor = R;
            }
        }
    }

    if (menor != pos){
        x = V[menor];
        V[menor] = V[pos];
        V[pos] = x;

        min_heapfy(H, menor);
    }
}


/*Insere um elemento e reorganiza as posições.

Coloca o elemento na última posição do heap, troca com o pai enquanto a prioridade do filho for menor.
Se a prioridade for igual, mas o timestamp for menor, também troca*/
void inserir(heap *H, par p){
    int i = H->size;
    par x;
    par *V = H->V;
    V[i] = p;
    H->size++;
    while (i>0 && V[i].prio <= V[(i-1)/2].prio){
        if (V[i].prio < V[(i-1)/2].prio){
            x = V[i];
            V[i] = V[(i-1)/2];
            V[(i-1)/2] = x;
        }
        else if (V[i].ts < V[(i-1)/2].ts){
            x = V[i];
            V[i] = V[(i-1)/2];
            V[(i-1)/2] = x;
        }
        i = (i-1)/2;
    }    
}


/*Remove o menor elemento do heap.

Substitui o elemento 0 (menor) pelo último do heap e ajusta a prioridade com min_heapfy*/
void rem_min(heap *H){
    par *V = H->V;
    H->size--;
    V[0] = V[H->size];
    min_heapfy(H, 0);
}

/*Libera a memória alocada para o heap *H*/
void libera(heap *H){
    free(H->V);
    free(H);
}