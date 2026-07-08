#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>

/**
 * @brief Struct that represents every elemnt in a hash map
 *
 * @var key a string literal that would be the key
 * @var val value to be stored
 * @var occupied Number that represents weather its space in memory
 *      has already been used (this is used for collisions)
 */
typedef struct {
    char *key;
    int val;
    int _occupied;
} MapItem;

// capacity of the array of elements for the hash map
#define ELEMENTS_CAP 200

/**
 * @brief Hash map struct
 *
 * @var VALUES
 */
typedef struct {
    MapItem elements[ELEMENTS_CAP];
    size_t count;
} HashMap;

void hash_map_insert(HashMap *hm, const char *key, int val);
void hash_map_deinit(HashMap *hm);
int hash_map_update(HashMap *hm, const char *key, int val);
int hash_map_get(HashMap *hm, const char *key, int *out);
void hash_map_println(HashMap *hm);

#endif
