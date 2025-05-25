#include "utils.c"
#include "hash_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

HashTable* ht_create(int size) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = size;
    ht->table = (Pair**)malloc(sizeof(Pair*) * size);
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

void ht_insert(HashTable* ht, const char* key, int value) {
    int index = hash_string(key, ht->size);
    Pair* current = ht->table[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            current->value = value; // Schlüssel existiert => Wert überschreiben
            return;
        }
        current = current->next;
    }

    Pair* new_pair = (Pair*)malloc(sizeof(Pair));
    new_pair->key = strdup(key); // neuen Schlüssel kopieren
    new_pair->value = value;
    new_pair->next = ht->table[index];
    ht->table[index] = new_pair;
}

int ht_get(HashTable* ht, const char* key) {
    int index = hash_string(key, ht->size);
    Pair* current = ht->table[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return -1; // nicht gefunden
}

bool ht_remove(HashTable* ht, const char* key) {
    int index = hash_string(key, ht->size);
    Pair* current = ht->table[index];
    Pair* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                ht->table[index] = current->next;
            }
            free(current->key);
            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}

void ht_free(HashTable* ht) {
    for (int i = 0; i < ht->size; ++i) {
        Pair* current = ht->table[i];
        while (current) {
            Pair* tmp = current;
            current = current->next;
            free(tmp->key);
            free(tmp);
        }
    }
    free(ht->table);
    free(ht);
}