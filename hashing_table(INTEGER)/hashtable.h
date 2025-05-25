#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct Pair {
    int key;
    int value;
    struct Pair* next;

} Pair;

typedef struct {
    int size;
    Pair** table;
} HashTable;

HashTable* create_table(int size);
void insert(HashTable* ht, int key, int value);
int get(HashTable* ht, int key);
int remove_key(HashTable* ht, int key);
void free_table(HashTable* ht);

#endif
