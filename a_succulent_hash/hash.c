#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    

// Hint strncpy and strcmp are useful

unsigned long hash(char* key){
    int result = 0;
    while (*key != '\0') {
        result += *key;
    }
    return result % 64;
}

void t_put(hashTable* tbl, char* key, int val){
    linkedList tmp = tbl->array[hash(key) % tbl->capacity];
    tmp.value = val;
}

int t_get(hashTable* tbl, char* key){
    return tbl->array[hash(key)%tbl->capacity].value;
}

int t_pop(hashTable* tbl, char* key){
    int popped = tbl->array[hash(key)%tbl->capacity].value;
    linkedList tmp = tbl->array[hash(key) % tbl->capacity];
    tmp.next = tmp.next->next;
    return  popped;
}

int t_init(hashTable* tbl, int capacity){
    tbl->array = malloc(sizeof(int)*capacity);
    tbl->capacity = capacity;
    
  
    for (int i = 0; i < capacity - 1; i++) {

        linkedList dummy_node;
        tbl->array[i] = dummy_node;

    }
}

int t_clear(hashTable* tbl){

    for (int i = 0; i <  tbl->capacity - 1; i++) {
        linkedList tmp = tbl->array[i];
        tmp.next = NULL;
    }
}
