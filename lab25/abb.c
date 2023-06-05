#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "abb.h"

node* cria(){
    node* arv = malloc(sizeof(node));
    if (arv == NULL){
        return NULL;
    }

    arv->key = 0;
    arv->nome = malloc(101*sizeof(char));
    arv->pontos = 0;
    arv->L = NULL;
    arv->R = NULL;

    return arv;
}



void libera(node* raiz){
    node* p = raiz;
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
        else if (p != raiz){
            free(p);
            p = raiz;

            n->L = NULL;
            n->R = NULL;
        }
        else{
            free(p);
            p = NULL;
        }
    }
}



int inserir(node* raiz, int k, char* nome, float pontos){
    if (raiz->key == 0){
        raiz->key = k;
        strcpy(raiz->nome, nome);
        raiz->pontos = pontos;
    }

    else{
        node* p = malloc(sizeof(node));
        if (p == NULL){
            printf("memoria insuficiente\n");
            return 1;
        }

        p->key = k;
        strcpy(p->nome, nome);
        p->pontos = pontos;
        p->L = NULL;
        p->R = NULL;

        node* n = raiz;

        while(1){
            if (k < n->key){
                if (n->L == NULL){
                    n->L = p;
                    return 0;
                }
                else{
                    n = n->L;
                }
            }
            else if(k > n->key){
                if (n->R == NULL){
                    n->R = p;
                    return 0;
                }
                else{
                    n = n->R;
                }
            }
            else{
                return 0;
            }
        }
    }

}



int remover(node* raiz, int k){

}



int buscar(node* raiz, int k){

}



int max(node* arv){

}



int min(node* arv){

}



int sucessor(node* arv, int k){

}



int predecessor(node* arv, int k){

}



int intervalo(node* arv, int x, int y){

}
