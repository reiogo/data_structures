#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    

// Hint strncpy and strcmp are useful

unsigned long hash(char* key){

    int result = 0;

    for (int i = 0; i < strlen(key); i++) {
        result += *key;
    }

    return result;

}

void t_put(hashTable* tbl, char* key, int val){

    linkedList tmp = tbl->array[hash(key) % tbl->capacity];
    while(tmp.next != NULL) {

        tmp = *tmp.next;
        
    }
    linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
    tmp.next = newNode;
    newNode->value = val;

        
}

int t_get(hashTable* tbl, char* key){

    linkedList tmp = tbl->array[hash(key) % tbl->capacity];
    while(tmp.key != key && tmp.key) {

        tmp = *tmp.next;
        
    }

    return tmp.value;
}

int t_pop(hashTable* tbl, char* key){

    linkedList tmp = tbl->array[hash(key) % tbl->capacity];
    while(tmp.key != key) {

        tmp = *tmp.next;
        
    }

    int popped = tmp.value;
    tmp.next = tmp.next->next;
    return  popped;
}

int t_init(hashTable* tbl, int capacity){

    tbl->array = malloc(sizeof(linkedList) * capacity);
    tbl->capacity = capacity;
    
  
    for (int i = 0; i < capacity - 1; i++) {

        linkedList dummy_node;
        dummy_node.next = NULL;
        tbl->array[i] = dummy_node;

    }
    return 0;
}

int t_clear(hashTable* tbl){

    for (int i = 0; i <  tbl->capacity - 1; i++) {
        linkedList tmp = tbl->array[i];
        tmp.next = 0;
    }
}

void main(){
	hashTable tbl;
	t_init(&tbl, 100);
	t_put(&tbl, "one", 1);
	t_put(&tbl, "two", 2);
	t_put(&tbl, "three", 3);
	

	t_put(&tbl, "four", 4);
	t_put(&tbl, "five", 5);
	t_put(&tbl, "six", 6);
	t_put(&tbl, "Bottles of beer on the wall", 99);

	printf("one %d\n", t_get(&tbl, "one"));
	printf("one %d\n", t_get(&tbl, "one"));
	printf("one %d\n", t_get(&tbl, "one"));

	printf("two %d\n", t_get(&tbl, "two"));
	printf("three %d\n", t_get(&tbl, "three"));

	printf("Bottles of beer on the wall %d\n", t_get(&tbl, "Bottles of beer on the wall"));
	printf("Waldo %d\n", t_get(&tbl, "Waldo"));

	printf("pop three %d\n", t_pop(&tbl, "three"));
	printf("pop three %d\n", t_pop(&tbl, "three"));
	printf("three %d\n", t_get(&tbl, "three"));

	printf("red %lu\n", hash("red") %100);
	printf("blue %lu\n", hash("blue")%100);
	printf("green %lu\n", hash("green")%100);
	printf("pinapple %lu\n", hash("pinapple")%100);
	printf("melon %lu\n", hash("melon")%100);
	printf("peach %lu\n", hash("peach")%100);
	printf("lemon %lu\n", hash("lemon")%100);
	printf("apple %lu\n", hash("apple")%100);

	t_clear(&tbl);

}
