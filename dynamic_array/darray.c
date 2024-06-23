#include "darray.h"
#include <stdlib.h>


void init(darray* a){
    a->size = 0;
    a->capacity = 1;
    a->data = calloc(1 , sizeof(int));
   
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

}

int main() {
    int num;
    char flag = 'c';
    darray b;

    init(&b);


    printf("To add number enter a number then 'c'\n To terminate add anything other than 'c'\n");

    while (flag != 'd') {
        scanf("%d %c", &num, &flag);

        if (flag == 'c') {
            append(&b, num);

        } else { 
            flag = 'd';

        }
    }


    printf("Array:\n");
    for(int i=0; i < b.size; i++) {
        printf("%d,",get(&b,i));
    }

    destroy(&b);
    
    return 0;
}
