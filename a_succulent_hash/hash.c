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
    tbl->array[hash(key)] = val;
}

int t_get(hashTable* tbl, char* key){
    return tbl->array[hash(key)];
}

int t_pop(hashTable* tbl, char* key){
    int popped = tbl->array[hash(key)];
    tbl->array[hash(key)] = 0;
    return  popped;
}

int t_init(hashTable* tbl, int capacity){
    tbl->array = malloc(sizeof(int)*capacity);
    
  
    for (int i = 0; i < capacity - 1; i++) {

        linkedList dummy_node;
        tbl->array[i] = dummy_node;

    }
}

int t_clear(hashTable* tbl){

    int hashTableLength = sizeof(tbl->array)/sizeof(tbl->array[0]);

    for (int i = 0; i <  hashTableLength - 1; i++) {
        tbl->array[i] = 0;
    }
}
