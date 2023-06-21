#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "heap.h"


/*Implementação de um heap binário de mínimo em C, com timestamps para desempatar prioridades iguais*/
int main(void){
    char func;
    unsigned key;
    int n, prio, ts = 0;
    heap *H = NULL;
    par p;

    scanf("%c ", &func);

    while(1){
        if (func == 'c'){
            if (H != NULL){
                libera(H);
            }

            scanf("%d\n", &n);
            H = cria(n);
            ts = 0;
        }

        else if (func == 'i'){
            scanf("%u %d\n", &key, &prio);
            p.key = key;
            p.prio = prio;
            p.ts = ts;
            inserir(H, p);
            ts++;
        }

        else if (func == 'r'){
            if (H->size > 0){
                rem_min(H);
            }
        }

        else if (func == 'm'){
            if (H->size == 0){
                printf("fila de prioridades vazia\n");
            }
            else{
                p = min(H->V);
                printf("prioridade minima %d, chave %d\n", p.prio, p.key);
            }
        }

        else if (func == 't'){
            libera(H);
            return 0;
        }

        else{
            printf("Comando inválido: %c", func);
            libera(H);
            return 1;
        }

        scanf("%c ", &func);
    }
}