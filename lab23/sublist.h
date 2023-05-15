#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


#ifndef PLAYLIST_H
#define PLAYLIST_H

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node node;

typedef struct{
    node* inicio;
    node* fim;
}lista;

lista* cria();


#endif