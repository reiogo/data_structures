#include <stdio.h>
#include <stdlib.h>

typedef struct darray{
    size_t size;
    size_t capacity;
    int *data;
}darray;


void init(darray* a);
void append(darray* a, int val);
int get(darray* a, int index);
void destroy(darray* a);
