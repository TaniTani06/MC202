#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "dequef.h"


/**
   Create an empty deque of floats.

   capacity is both the initial and minimum capacity.
   factor is the resizing factor, larger than 1.0.

   On success it returns the address of a new dequef.
   On failure it returns NULL.
**/
dequef* df_alloc(long capacity, double factor) {
   dequef* D;
   D = malloc(sizeof(dequef));
   if (D == NULL){
      return D;
   }

   D->data = (float*)calloc(capacity, sizeof(float));

   D->first = 0;
   D->size = 0;

   D->cap = capacity;
   D->mincap = capacity;
   D->factor = factor;

   return D;
}



/**
  Release a dequef and its data.
**/
void df_free(dequef* D) {
   free(D->data);
   free (D);
}



/**
   The size of the deque.
**/
long df_size(dequef* D) {
   return D->size;
}



int df_resize(dequef* D, long new_cap) {
   float* new_data;
   int pos;

   new_data = (float*)calloc(new_cap, sizeof(float));

   if (new_data == NULL){
      return 0;
   }
   else{
      for (int i = 0; i < D->size; i++){

         pos = i + D->first;
         if (pos >= D->cap){
            pos -= D->cap;
         }
         new_data[i] = D->data[pos];
      }

      free (D->data);
      D->data = new_data;
      D->cap = new_cap;
      
      return 1;
   }
}



/**
   Add x to the end of D.

   If the array is full, it first tries to increase the array size to
   capacity*factor.

   On success it returns 1.
   If attempting to resize the array fails then it returns 0 and D remains unchanged.
**/
int df_push(dequef* D, float x) {
   int successo = 1;
   int pos;

   if (D->size == D->cap){
      successo = df_resize(D, ((D->factor)*(D->cap)));
      if (successo == 0){
         return 0;
      }
   }
   
   pos = D->first + D->size;
   if (pos >= D->cap){
      pos -= D->cap;
   }

   D->data[pos] = x;
   D->size++;
   
   return 1;
}



/**
   Remove a float from the end of D.

   If the deque has capacity/(factor^2) it tries to reduce the array size to
   capacity/factor.  If capacity/factor is smaller than the minimum capacity,
   the minimum capacity is used instead.  If it is not possible to resize, then
   the array size remains unchanged.

   This function returns the float removed from D.
   If D was empty prior to invocation, it returns 0.0 and D remains unchanged.
**/
float df_pop(dequef* D) {
   float f;

   if (D->size == 0){
      return 0.0;
   }

   f = D->data[D->size-1];
   D->size--;

   if ((float)D->size <= (D->cap)/((D->factor)*(D->factor)) && D->cap >= (D->factor)*(D->mincap)){
      df_resize(D, ((D->cap)/(D->factor)));
   }

   return f;
}



/**
   Add x to the beginning of D.

   If the array is full, it first tries to increase the array size to
   capacity*factor.

   On success it returns 1.
   If attempting to resize the array fails then it returns 0 and D remains unchanged.
**/
int df_inject(dequef* D, float x) {
   int successo = 1;
   int pos;

   if (D->size == D->cap){
      successo = df_resize(D, ((D->factor)*(D->cap)));
      if (successo == 0){
         return 0;
      }
   }

   pos = D->first - 1;
   if (pos <= 0){
      pos += D->cap;
   }

   D->data[pos] = x;
   D->first = pos;
   D->size++;

   return 1;
}



/**
   Remove a float from the beginning of D.

   If the deque has capacity/(factor^2) elements, this function tries to reduce
   the array size to capacity/factor.  If capacity/factor is smaller than the
   minimum capacity, the minimum capacity is used instead.

   If it is not possible to resize, then the array size remains unchanged.

   This function returns the float removed from D.
   If D was empty prior to invocation, it returns 0.0 and D remains unchanged.
**/
float df_eject(dequef* D) {
   float f;

   if (D->size == 0){
      return 0.0;
   }

   f = D->data[D->first];
   D->first++;
   if (D->first >= D->cap){
      D->first -= D->cap;
   }

   D->size--;

   if ((float)D->size <= (D->cap)/((D->factor)*(D->factor)) && D->cap >= (D->factor)*(D->mincap)){
      df_resize(D, ((D->cap)/(D->factor)));
   }

   return f;
}



/**
   Set D[i] to x.

   If i is not in [0,|D|-1]] then D remains unchanged.
**/
void df_set(dequef* D, long i, float x) {
   int pos;

   pos = i + D->first;
   if (pos >= D->cap){
      pos -= D->cap;
   }

   D->data[pos] = x;
}



/**
   Return D[i].

   If i is not in [0,|D|-1]] it returns 0.0.
**/
float df_get(dequef* D, long i) {
   int pos;

   pos = i + D->first;
   if (pos >= D->cap){
      pos -= D->cap;
   }

   return D->data[pos];
}



/**
   Print the elements of D in a line.
**/
void df_print(dequef* D) {
   int pos;

   printf("deque (%ld):", df_size(D));
   for (int i = 0; i < df_size(D); i++){
      pos = i + D->first;                      //não necessariamente o primeiro elemento do deque é o array[0];
      
      if (pos >= D->cap){                       //faz a "volta", pois é um vetor circular
         pos -=  D->cap;                       //se o primeiro elemento for 6 em uma array de tamanho 8: (6,7,0,1,...)
      }

      printf(" %.1f", D->data[pos]);
   }
   printf(" \n");                              //talvez dê problema o ' \n' (em vez de '\n')
}
