#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>

struct MapItem {
    char *key;
    int val;
    int occupied;
};

#define VALUES_LEN 200

struct HashMap {
    struct MapItem VALUES[VALUES_LEN];
};

void hash_map_insert(struct HashMap *hm, char *key, int val);
int hash_map_get(struct HashMap *hm, char *key);
void hash_map_println(struct HashMap *hm);

#endif
