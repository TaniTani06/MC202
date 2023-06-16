#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "abb.h"

abb* cria(){
    abb* A = malloc(sizeof(abb));
    if (A == NULL){
        return NULL;
    }

    A->raiz = NULL;

    return A;
}



void libera(abb* A){
    node* p = A->raiz;
    node* n = NULL;

    while (p != NULL){
        if (p->L != NULL){
            p = p->L;
        }
        else if (p->R != NULL){
            p = p->R;
        }
        else if (p != A->raiz){
            n = p->pai;

            if (n->L == p){
                free(p);
                n->L = NULL;
            }
            else{
                free(p);
                n->R = NULL;
            }
            p = A->raiz;
        }
        else{
            free(p);
            A->raiz = NULL;
            p = NULL;
        }
    }
    free(A);
}



int inserir(abb* A, int k, char* nome, float pontos){
    if (buscar(A->raiz, k) != NULL){
        return 0;
    }

    node* z = malloc(sizeof(node));
    if (z == NULL){
        printf("memoria insuficiente\n");
        return 1;
    }

    z->key = k;
    strcpy(z->nome, nome);
    z->pontos = pontos;
    z->L = NULL;
    z->R = NULL;

    node* n = A->raiz;
    node* p = NULL;

    while(n != NULL){
        p = n;
        if (z->key < n->key){
            n = n->L;
        }
        else{
            n = n->R;
        }
    }

    if (p == NULL){
        A->raiz = z;
        z->pai = NULL;
    }
    else if (z->key < p->key){
        p->L = z;
        z->pai = p;
    }
    else if (z->key > p->key){
        p->R = z;
        z->pai = p;
    }

    return 0;
}



node* buscar(node* raiz, int k){
    node* u = raiz;

    while ((u != NULL) && (k != u->key)){
        if (k < u->key){
            u = u->L;
        }
        else{
            u = u->R;
        }
    }
    return u;
}



node* max(node* raiz){
    node* u = raiz;

    if (u == NULL){
        return NULL;
    }
    while(u->R != NULL){
        u = u->R;
    }
    return u;
}



node* min(node* raiz){
    node* u = raiz;

    if (u == NULL){
        return NULL;
    }
    while(u->L != NULL){
        u = u->L;
    }
    return u;
}



node* sucessor(node* raiz, int k){
    node* u = buscar(raiz, k);

    if (u->R != NULL){
        return min(u->R);
    }

    node* p = u->pai;

    while ((p != NULL) && (u == p->R)){
        u = p;
        p = p->pai;
    }

    return p;
}



node* predecessor(node* raiz, int k){
    node* u = buscar(raiz, k);

    if (u->L != NULL){
        return max(u->L);
    }

    node* p = u->pai;

    while ((p != NULL) && (u == p->L)){
        u = p;
        p = p->pai;
    }

    return p;
}



int subs(abb* A, node* u, node* v){
    if (u->pai == NULL){
        A->raiz = v;
    }
    else if (u == u->pai->L){
        u->pai->L = v;
    }
    else{
        u->pai->R = v;
    }

    if (v != NULL){
        v->pai = u->pai;
    }
    return 0;
}



int remover(abb* A, int k){
    node* z = buscar(A->raiz, k);
    node* pai;
    if (z == NULL){
        return 0;
    }
    pai = z->pai;

    if ((z->L == NULL) && (z->R == NULL)){
        if (pai == NULL){
        free(z);
        A->raiz = NULL;
        }
        else if (pai->L == z){
            free(z);
            pai->L = NULL;
        }
        else{
            free(z);
            pai->R = NULL;
        }

        return 0;
    }


    if (z->L == NULL){
        subs(A, z, z->R);
    }

    else if (z->R == NULL){
        subs(A, z, z->L);
    }

    else{
        node* u = min(z->R);

        if (u->pai != z){
            subs(A, u, u->R);
            u->R = z->R;
            u->R->pai = u;
        }

        subs(A, z, u);
        u->L = z->L;
        u->L->pai = u;
    }

    free(z);

    return 0;
}



int intervalo(abb* A, int x, int y){
    printf("clientes no intervalo [%d,%d]: ", x, y);
    
    node* u = buscar(A->raiz, x);
    if (u == NULL){
        u = min(A->raiz);
        while (u->key < x){
            u = sucessor(A->raiz, u->key);
        }
    }

    node* v = buscar(A->raiz, y);
    if (v == NULL){
        v = max(A->raiz);
        while (v->key > y){
            v = predecessor(A->raiz, v->key);
        }
    }

    if (u->key > v->key){
        printf("nenhum\n");
        return 0;
    }
    while ((u != v) && (u != NULL)){
        printf("%d ", u->key);
        u = sucessor(A->raiz, u->key);
    }
    printf("%d \n", v->key);

    return 0;
}



int imprimir(node* raiz){
    if (raiz->L != NULL){
        imprimir(raiz->L);
    }

    printf("%s (%d) ", raiz->nome, raiz->key);

    if (raiz->R != NULL){
        imprimir(raiz->R);
    }
    return 0;
}