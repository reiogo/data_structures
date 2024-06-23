#include "darray.h"
#include <stdlib.h>
#include <string.h>


void init(darray* a){
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
    return a->data[index];

}


void destroy(darray* a){
    free(a->data);
    free(a);

}

int main() {
    int num = 0;
    char flag = 'c';
    darray *b;

    init(b);


    while (flag != 'd') {
        printf("Enter a number, if done enter d\n");
        
        if (scanf("%d", &num)) {
            append(b, num);

        } else if (scanf("%c", &flag) == 'd') { 
            flag = 'd';

        }
    }


    /* printf("Array:\n"); */
    /* for(int i=0; i < b->size; i++) { */
    /*     printf("%d,",get(b,i)); */
    /* } */

    /* destroy(b); */
    /* printf("freed memory address:%p", b); */
    
    return 0;
}
