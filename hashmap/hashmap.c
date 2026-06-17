#include "hashmap.h"

#include <stddef.h>
#include <stdio.h>

#define VALUES_LEN 200

struct MapItem VALUES[VALUES_LEN] = {0};

static size_t _hash_str(char *s) {
    size_t hash = 0;

    for (size_t i = 0; s[i] != '\0'; ++i) {
        hash = (hash * 31 + (size_t)s[i]);
    }

    return hash;
}

static size_t _get_index(char *s) {
    return _hash_str(s) % VALUES_LEN;
}

static void set_map_item(struct MapItem *mi, char *key, int val, int occupied) {
    mi->key = key;
    mi->val = val;
    mi->occupied = occupied;
}

void hash_insert(char *key, int val) {
    size_t index = _get_index(key);
    int amount = 1;

    if (VALUES[index].occupied) {
        if (index == VALUES_LEN - 1) {
            amount = -1;
        }

        while (VALUES[index].occupied) {
            index += (size_t)amount;
        }

        set_map_item(&VALUES[index], key, val, 1);

        return;
    }

    set_map_item(&VALUES[index], key, val, 1);
}

int hash_get(char *key) {
    return VALUES[_get_index(key)].val;
}

void hash_println() {
    for (size_t i = 0; i < VALUES_LEN; ++i) {
        if (VALUES[i].occupied) {
            printf("%s: %d\n", VALUES[i].key, VALUES[i].val);
        }
    }
}
