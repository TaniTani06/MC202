#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "recon.h"



node* cria(char raiz){
    node* arv = malloc(sizeof(node));
    if (arv == NULL){
        return NULL;
    }

    arv->data = raiz;
    arv->L = NULL;
    arv->R = NULL;

    return arv;
}



void libera(node* arv){
    node* p = malloc(sizeof(node));
    p = arv;

    while (p != NULL){
        if (p->L != NULL){
            p = p->L;
        }
        else if (p->R != NULL){
            p = p->R;
        }
        else if (p != arv){
            free(p);
            p = arv;
        }
        else{
            free(p);
            p = NULL;
        }
    }
}



int adiciona(node* arv, char data, char* em){
    node* p = malloc(sizeof(node));
    p = arv;

    char* pos;

    pos = strchr(em, p->data);
    int pos_p = pos - em;

    pos = strchr(em, data);
    int pos_data = pos - em;

    while (1){
        if (pos_data < pos_p){
            if (p->L == NULL){
                p->L = malloc(sizeof(node));
                p->L->data = data;
                p->L->L = NULL;
                p->L->R = NULL;
                return 0;
            }
            else{
                p = p->L;
                pos = strchr(em, p->data);
                pos_p = pos - em;
            }
        }

        if (pos_data > pos_p){
            if (p->R == NULL){
                p->R = malloc(sizeof(node));
                p->R->data = data;
                p->R->L = NULL;
                p->R->R = NULL;
                return 0;
            }
            else{
                p = p->R;
                pos = strchr(em, p->data);
                pos_p = pos - em;
            }
        }
    }
}



int pos(node* arv){
    if (arv->L != NULL){
        pos(arv->L);
    }
    if (arv->R != NULL){
        pos(arv->R);
    }

    printf("%c", arv->data);
}



void enq(fila Q, node* arv){
    Q.F[Q.posf] = arv;
    Q.posf++;
    Q.empty = 0;
}



node* dequeue(fila Q){
    node* p = malloc(sizeof(node));

    p = Q.F[Q.posi];
    Q.F[Q.posi] = 0;
    Q.posi++;
    if (Q.posi == Q.posf){
        Q.empty = 1;
    }

    return p;
}



int larg(node* arv){
    fila Q;
    Q.posi = 0;
    Q.posf = 0;
    Q.empty = 1;

    node* p = malloc(sizeof(node));

    enq(Q,arv);
    
    while (Q.empty = 0){
        p = dequeue(Q);
        printf("%c", p->data);

        if (p->L != NULL){
            enq(Q,p->L);
        }
        if (p->L != NULL){
            enq(Q,p->L);
        }
    }
}