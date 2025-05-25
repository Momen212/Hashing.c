#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>

typedef struct Pair { 
    char* key;
    int value;
    struct Pair* next;
} Pair;

typedef struct {
    int size;
    Pair** table;
} HashTable;


HashTable* ht_create(int size);

void ht_insert(HashTable* ht, const char* key, int value);

int ht_get(HashTable* ht, const char* key);

bool ht_remove(HashTable* ht, const char* key);

void ht_free(HashTable* ht);

#endif // HASH_TABLE_H
