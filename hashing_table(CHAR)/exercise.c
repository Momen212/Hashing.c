#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash_table.c"

#define CMD_LEN 2
#define KEY_LEN 100

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Error: length of the Input Array < 1\n");
        return 1;
    }

    HashTable* table = ht_create(n);

    char command[CMD_LEN];
    char key[KEY_LEN];
    int value;

    while (1) {
        if (scanf("%s", command) != 1) break;

        if (command[0] == 'q') {
            break;
        } else if (command[0] == 'i') {
            if (scanf("%s %d", key, &value) == 2) {
                ht_insert(table, key, value);
                printf("Inserted (%s, %d)\n", key, value);
            }
        } else if (command[0] == 'g') {
            if (scanf("%s", key) == 1) {
                int result = ht_get(table, key);
                if (result == -1) {
                    printf("Key not found.\n");
                } else {
                    printf("Key: %s, Value: %d\n", key, result);
                }
            }
        } else if (command[0] == 'r') {
            if (scanf("%s", key) == 1) {
                bool removed = ht_remove(table, key);
                if (removed){
                    printf("Key %s removed: %s\n", key, "true" );
                }
                else{
                printf("Key %s removed: %s\n", key, "false");
                }
            }
        }
    }

    ht_free(table);
    return 0;
}
