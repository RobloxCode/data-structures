// #define _POSIX_C_SOURCE 200809L

#include "hashmap.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t _hash_str(const char *s) {
    size_t hash = 0;

    for (size_t i = 0; s[i] != '\0'; ++i) {
        hash = (hash * 31 + (size_t)s[i]);
    }

    return hash;
}

static size_t _get_index(const char *s) {
    return _hash_str(s) % VALUES_LEN;
}

static char *_my_strdup(const char *s) {
    size_t len = strlen(s) + 1;

    char *copy = malloc(len);
    if (!copy) {
        return NULL;
    }

    memcpy(copy, s, len);

    return copy;
}

static int set_map_item(struct MapItem *mi, const char *key, int val,
                        int occupied) {
    char *copy = _my_strdup(key);

    if (!copy) {
        return 1;
    }

    mi->key = copy;
    mi->val = val;
    mi->occupied = occupied;

    return 0;
}

void hash_map_deinit(struct HashMap *hm) {
    for (size_t i = 0; i < VALUES_LEN; ++i) {
        if (hm->VALUES[i].occupied) {
            free(hm->VALUES[i].key);
        }
    }
}

void hash_map_insert(struct HashMap *hm, const char *key, int val) {
    size_t i = _get_index(key);

    if (hm->VALUES[i].occupied) {
        if (strcmp(hm->VALUES[i].key, key) == 0) {
            return;
        }

        while (hm->VALUES[i].occupied) {
            i = (i + 1) % VALUES_LEN;
        }

        if (set_map_item(&(hm->VALUES[i]), key, val, 1) != 0) {
            fprintf(stderr, "Error while assigning key\n");
            return;
        }

        hm->values_count++;

        return;
    }

    if (set_map_item(&(hm->VALUES[i]), key, val, 1) != 0) {
        fprintf(stderr, "Error while assigning key\n");
        return;
    }

    hm->values_count++;
}

int hash_map_update(struct HashMap *hm, const char *key, int val) {
    size_t i = _get_index(key);

    while (hm->VALUES[i].occupied) {
        if (strcmp(hm->VALUES[i].key, key) == 0) {
            hm->VALUES[i].val = val;
            return 0;
        }

        i = (i + 1) % VALUES_LEN;
    }

    return 1;
}

int hash_map_get(struct HashMap *hm, const char *key, int *out) {
    if (!out || !key || !hm) {
        return 1;
    }

    size_t i = _get_index(key);

    while (hm->VALUES[i].occupied) {
        if (strcmp(hm->VALUES[i].key, key) == 0) {
            *out = hm->VALUES[i].val;
            return 0;
        }

        i = (i + 1) % VALUES_LEN;
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
