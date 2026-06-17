#include <stddef.h>
#include <stdio.h>

#define VALUES_LEN 200

int VALUES[VALUES_LEN] = {0};

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

void hash_insert(char *key, int val) {
    VALUES[_get_index(key)] = val;
}

int hash_get(char *key) {
    return VALUES[_get_index(key)];
}

void hash_println() {
    for (size_t i = 0; i < VALUES_LEN; ++i) {
        printf("%d\n", VALUES[i]);
    }
}
