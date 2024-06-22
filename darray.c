#include "darray.h"
#include <stdio.h>
#include <stdlib.h>


void init(darray* a){
    a = malloc(sizeof(darray));
    a->size = 0;
    a->capacity = 8;
    a->data = calloc(8 , sizeof(int));
   
}


void append(darray* a, int val){
    a->size++;

    if (a->size >= a->capacity) {
      a->capacity = 2 * a->size;
      a->data = realloc(a->data, a->capacity*sizeof(int));
      a->data[a->size -1 ] = val; 
    } else { 
      a->data[a->size - 1] = val;
    }
 }


int get(darray* a, int index){

}


void destroy(darray* a){
    free(a->data);
    free(a);

}

