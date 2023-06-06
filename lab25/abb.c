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
        else if (p != A->raiz){
            free(p);
            p = A->raiz;

            n->L = NULL;
            n->R = NULL;
        }
        else{
            free(p);
            p = NULL;
        }
    }
    free(A);
}



int inserir(abb* A, int k, char* nome, float pontos){
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
}



int remover(abb* A, int k){
    node* z = buscar(A->raiz, k);
    if (z == NULL){
        return 0;
    }

    if ((z->L == NULL) && (z->R == NULL)){
        if (z->pai->L == z){
            free(z);
            z->pai->L = NULL;
        }
        else{
            free(z);
            z->pai->R = NULL;
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



int intervalo(abb* A, int x, int y){ //não funciona se x e y nao estiverem na arvore
    printf("clientes no intervalo [%d,%d]: ", x, y);
    
    node* u = buscar(A->raiz, x);
    while (u == NULL){
        x++;
        u = buscar(A->raiz, x);
    }

    node* v = buscar(A->raiz, y);
    while (v == NULL){
        y--;
        v = buscar(A->raiz, y);
    }

    if (u == v){
        printf("nenhum\n");
        return 0;
    }
    while (u != v){
        printf("%d ", u->key);
        u = sucessor(A->raiz, u->key);
    }
    printf("%d \n", v->key);

    return 0;
}
