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
    size_t values_count;
};

void hash_map_insert(struct HashMap *hm, const char *key, int val);
void hash_map_deinit(struct HashMap *hm);
int hash_map_update(struct HashMap *hm, const char *key, int val);
int hash_map_get(struct HashMap *hm, const char *key, int *out);
void hash_map_println(struct HashMap *hm);

#endif
