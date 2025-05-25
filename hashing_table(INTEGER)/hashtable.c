#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"

static int address_of_list(int key, int size) {
    int hash = key % size;
    if (hash<0) return hash + size;
    else return hash;
}
HashTable* create_table(int size) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = size;
    ht->table = (Pair**)malloc(sizeof(Pair*) * size);
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}
void insert(HashTable* ht, int key, int value) {
    int index = address_of_list(key, ht->size);
    Pair* current = ht->table[index];

    while (current != NULL) {
        if (current->key == key) {
            current->value = value; // Überschreiben
            return;
        }
        current = current->next;
    }

    Pair* new_pair = (Pair*)malloc(sizeof(Pair));
    new_pair->key = key;
    new_pair->value = value;
    new_pair->next = ht->table[index];
    ht->table[index] = new_pair;
}
int get(HashTable* ht, int key) {
    int index = address_of_list(key, ht->size);
    Pair* current = ht->table[index];

    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    return 0; // nicht gefunden 
}
int remove_key(HashTable* ht, int key) {
    int index = address_of_list(key, ht->size);
    Pair* current = ht->table[index];
    Pair* prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                ht->table[index] = current->next;
            }
            free(current);
            return 1; // true
        }
        prev = current;
        current = current->next;
    }

    return 0; // false
}
 
void free_table(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        Pair* current = ht->table[i];
        while (current != NULL) {
            Pair* tmp = current;
            current = current->next;
            free(tmp);
        }
    }
    free(ht->table);
    free(ht);
}