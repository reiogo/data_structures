#define KEY_MAX_LENGTH 64

typedef struct linkedList {
    void* key;
    void* value;
    struct linkedList* next;

}linkedList;

typedef struct hashTable{
    linkedList* array;


%}hashTable;


unsigned long hash(char* key);
void t_put(hashTable*, char* key, int val);
int t_get(hashTable*, char* key);
int t_pop(hashTable*, char* key);
int t_init(hashTable*, int capacity);
int t_clear(hashTable*);
