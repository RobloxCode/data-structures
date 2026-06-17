#include "hashmap.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>

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

void hash_map_insert(struct HashMap *hm, char *key, int val) {
    size_t index = _get_index(key);
    int amount = 1;

    if (hm->VALUES[index].occupied) {
        if (index == VALUES_LEN - 1) {
            amount = -1;
        }

        while (hm->VALUES[index].occupied) {
            index += (size_t)amount;
        }

        set_map_item(&(hm->VALUES[index]), key, val, 1);

        return;
    }

    set_map_item(&(hm->VALUES[index]), key, val, 1);
    hm->values_count++;
}

int hash_map_get(struct HashMap *hm, char *key, int *out) {
    if (!out || !key || !hm) {
        return 1;
    }

    size_t index = _get_index(key);

    while (hm->VALUES[index].occupied) {
        if (strcmp(hm->VALUES[index].key, key) == 0) {
            *out = hm->VALUES[index].val;
            return 0;
        }

        index = (index + 1) % VALUES_LEN;
    }

    return 1;
}

void hash_map_println(struct HashMap *hm) {
    for (size_t i = 0; i < VALUES_LEN; ++i) {
        if (hm->VALUES[i].occupied) {
            printf("{%s: %d}\n", hm->VALUES[i].key, hm->VALUES[i].val);
        }
    }
    printf("\n");
}
