#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.c"

#define CMD_LEN 2 // Befehllänge (1) + Null-Terminator
 
int main() {

    char command[CMD_LEN];
    int n;
    scanf("%d",&n);
    if (n<1 || n>1000) return 0;

    HashTable* ht = create_table(n);

    while (1) {
        scanf("%s", command);
        if (command[0] == 'q') {
            break;
        } else if (command[0] == 'i') {
            int key, value;
            scanf("%d %d", &key, &value);
            insert(ht, key, value);
            printf("Inserted (%d, %d)\n", key, value);
        } else if (command[0] == 'g') {
            int key;
            scanf("%d", &key);
            int result = get(ht, key);
            if (result == 0) {
                printf("Key not found.\n");
            } else {
                printf("Key: %d, Value: %d\n", key, result);
            }
        } else if (command[0] == 'r') {
            int key;
            scanf("%d", &key);
            int removed = remove_key(ht, key);
            if (removed){
                printf("Key %d removed: %s\n", key, "true" );}
            else {
                printf("Key %d removed: %s\n", key, "false");
            }
        }
    }


    return 0;
}
