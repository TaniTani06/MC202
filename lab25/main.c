#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "abb.h"

int main(void){
    int k, x, y;
    float pts;
    char func[18], nome[101];
    abb* A = NULL;
    node* u;

    while (1){
        scanf("%s", func);

        if (strcmp(func, "criar") == 0){
            if (A != NULL){
                libera(A);
            }
            A = cria();
        }

        else if (strcmp(func, "inserir") == 0){
            scanf("%d, %[^,], %f\n", &k, nome, &pts);

            inserir(A, k, nome, pts);
        }

        else if (strcmp(func, "remover") == 0){
            scanf("%d\n", &k);

            remover(A, k);
        }

        else if (strcmp(func, "buscar") == 0){
            scanf("%d\n", &k);

            u = buscar(A->raiz, k);
            if (u != NULL){
                printf("cliente %d: %s, %.2f pontos\n", k, u->nome, u->pontos);
            }
            else{
                printf("nao ha cliente %d\n", k);
            }
        }

        else if (strcmp(func, "imprimir") == 0){
            if (A->raiz == NULL){
                printf("arvore vazia\n");
            }
            else{
                printf("clientes: ");
                imprimir(A->raiz);
                printf("\n");
            }
        }

        else if (strcmp(func, "minimo") == 0){
            u = min(A->raiz);
            if (u != NULL){
                printf("minimo: %d\n", u->key);
            }
            else{
                printf("arvore vazia\n");
            }
        }

        else if (strcmp(func, "maximo") == 0){
            u = max(A->raiz);
            if (u != NULL){
                printf("maximo: %d\n", u->key);
            }
            else{
                printf("arvore vazia\n");
            }
        }

        else if (strcmp(func, "sucessor") == 0){
            scanf("%d\n", &k);

            u = buscar(A->raiz, k);
            if (u == NULL){
                printf("nao ha cliente %d\n", k);
            }
            else{
                printf("sucessor de %d: ", k);
                u = sucessor(A->raiz, k);
                if (u != NULL){
                    printf("%d\n", u->key);
                }
                else{
                    printf("nao ha\n");
                }
            }
        }

        else if (strcmp(func, "predecessor") == 0){
            scanf("%d\n", &k);

            u = buscar(A->raiz, k);
            if (u == NULL){
                printf("nao ha cliente %d\n", k);
            }
            else{
                printf("predecessor de %d: ", k);
                u = predecessor(A->raiz, k);
                if (u != NULL){
                    printf("%d\n", u->key);
                }
                else{
                    printf("nao ha\n");
                }
            }
        }

        else if (strcmp(func, "buscar-intervalo") == 0){
            scanf("%d %d", &x, &y);

            intervalo(A, x, y);
        }

        else if (strcmp(func, "terminar") == 0){
            libera(A);
            return 0;
        }

        else {
            printf("Ups! invalid command: %s.\n",func);
            libera(A);
            return 1;
        }
    }
}