#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>

/**
 * @brief Struct that represents every elemnt in a hash map
 *
 * @var key a string literal that would be the key
 * @var val value to be stored
 * @var occupied Number that represents wheter its space in memory
 *      has already been used (this is used for collisions)
 */
typedef struct {
    char *key;     /* < heap allocated string */
    int val;       /* < every individual value a*/
    int _occupied; /* < wheter or not a space has been used*/
} MapItem;

// capacity of the array of elements for the hash map
#define ELEMENTS_CAP 200

/**
 * @brief Hash map struct
 *
 * @var elements Array of MapItem
 * @var count the current amount of elements stored
 */
typedef struct {
    MapItem elements[ELEMENTS_CAP];
    size_t count;
} HashMap;

/**
 * @brief adds a new element to the hash map
 *
 * @param hm Pointer to HashMap
 * @param key String that will be the key
 * @param val Value to be added
 */
void hash_map_insert(HashMap *hm, const char *key, int val);

/**
 * @brief Frees the keys since they are heap allocated
 *
 * @param hm Pointer to HashMap
 */
void hash_map_deinit(HashMap *hm);

/**
 * @brief Change an existing value within the hash map's elements
 *
 * @param hm Pointer to HashMap
 * @param key String that will be the key
 * @param val new number to be changed
 */
int hash_map_update(HashMap *hm, const char *key, int val);

/**
 * @brief Retrieve an element with a given key
 *
 * @param hm Pointer to HashMap
 * @param key String that will be the key
 * @param out Pointer to the buffer output
 */
int hash_map_get(HashMap *hm, const char *key, int *out);

/**
 * @brief prints to stdout the hash map elemnts with format {key: value}
 *
 * @param hm Pointer to HashMap
 */
void hash_map_println(HashMap *hm);

#endif
