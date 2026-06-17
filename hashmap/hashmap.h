#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>

struct MapItem {
    char *key;
    int val;
    int occupied;
};

void hash_insert(char *key, int val);
int hash_get(char *key);
void hash_println();

#endif
