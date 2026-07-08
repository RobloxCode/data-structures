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
    return _hash_str(s) % ELEMENTS_CAP;
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

static int set_map_item(MapItem *mi, const char *key, int val, int occupied) {
    char *copy = _my_strdup(key);

    if (!copy) {
        return 1;
    }

    mi->key = copy;
    mi->val = val;
    mi->_occupied = occupied;

    return 0;
}

void hash_map_deinit(HashMap *hm) {
    for (size_t i = 0; i < ELEMENTS_CAP; ++i) {
        if (hm->elements[i]._occupied) {
            free(hm->elements[i].key);
        }
    }
}

void hash_map_insert(HashMap *hm, const char *key, int val) {
    size_t i = _get_index(key);

    if (hm->elements[i]._occupied) {
        if (strcmp(hm->elements[i].key, key) == 0) {
            return;
        }

        while (hm->elements[i]._occupied) {
            i = (i + 1) % ELEMENTS_CAP;
        }

        if (set_map_item(&(hm->elements[i]), key, val, 1) != 0) {
            fprintf(stderr, "Error while assigning key\n");
            return;
        }

        hm->count++;

        return;
    }

    if (set_map_item(&(hm->elements[i]), key, val, 1) != 0) {
        fprintf(stderr, "Error while assigning key\n");
        return;
    }

    hm->count++;
}

int hash_map_update(HashMap *hm, const char *key, int val) {
    size_t i = _get_index(key);

    while (hm->elements[i]._occupied) {
        if (strcmp(hm->elements[i].key, key) == 0) {
            hm->elements[i].val = val;
            return 0;
        }

        i = (i + 1) % ELEMENTS_CAP;
    }

    return 1;
}

int hash_map_get(HashMap *hm, const char *key, int *out) {
    if (!out || !key || !hm) {
        return 1;
    }

    size_t i = _get_index(key);

    while (hm->elements[i]._occupied) {
        if (strcmp(hm->elements[i].key, key) == 0) {
            *out = hm->elements[i].val;
            return 0;
        }

        i = (i + 1) % ELEMENTS_CAP;
    }

    return 1;
}

void hash_map_println(HashMap *hm) {
    for (size_t i = 0; i < ELEMENTS_CAP; ++i) {
        if (hm->elements[i]._occupied) {
            printf("{%s: %d}\n", hm->elements[i].key, hm->elements[i].val);
        }
    }
    printf("\n");
}
