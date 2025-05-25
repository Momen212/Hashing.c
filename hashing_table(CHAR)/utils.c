#include <stdlib.h>
#include <string.h>
#include "utils.h"

char* strdup(const char* str) {
    if (!str) return NULL;
    size_t len = strlen(str) + 1;
    char* copy = (char*)malloc(len);
    if (copy) {
        strcpy(copy, str);
    }
    return copy;
}

int hash_string(const char* str, int size) {
    int hash = 0;
    while (*str)hash = (hash * 31 + *str++) & 0x7fffffff;
    return hash % size;
}
