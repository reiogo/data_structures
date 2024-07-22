#define KEY_MAX_LENGTH 64

typedef struct linkedList {
    char* key;
    int value;
    struct linkedList* next;

}linkedList;

typedef struct hashTable{
    linkedList* array;
    int capacity;


}hashTable;


unsigned long hash(char* key);
void t_put(hashTable*, char* key, int val);
int t_get(hashTable*, char* key);
int t_pop(hashTable*, char* key);
int t_init(hashTable*, int capacity);
int t_clear(hashTable*);
