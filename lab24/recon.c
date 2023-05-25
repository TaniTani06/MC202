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
    node* p = arv;
    node* n;

    while (p != NULL){
        if (p->L != NULL){
            n = p;
            p = p->L;
        }
        else if (p->R != NULL){
            n = p;
            p = p->R;
        }
        else if (p != arv){
            n->L = NULL;
            n->R = NULL;

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
    node* p = arv;
    node* n = malloc(sizeof(node));

    n->L = NULL;
    n->R = NULL;
    n->data = data;

    char* pos;

    pos = strchr(em, p->data);
    int pos_p = pos - em;

    pos = strchr(em, data);
    int pos_data = pos - em;

    while (1){
        if (pos_data < pos_p){
            if (p->L == NULL){
                p->L = n;
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
                p->R = n;
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



void pos(node* arv){
    if (arv->L != NULL){
        pos(arv->L);
    }
    if (arv->R != NULL){
        pos(arv->R);
    }

    printf("%c", arv->data);
}



void larg(node* arv){
    
    node* fila[100];
    int frente = 0;
    int tras = 0;
    
    
    fila[tras++] = arv;
    
    while (frente < tras) {
        node* p = fila[frente++];
        printf("%c", p->data);
    
        if (p->L != NULL)
            fila[tras++] = p->L;
    
        if (p->R != NULL)
            fila[tras++] = p->R;
    }
}
