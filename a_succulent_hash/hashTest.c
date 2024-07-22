#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
