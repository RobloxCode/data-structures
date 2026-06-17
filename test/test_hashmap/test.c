#include "../../hashmap/hashmap.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

void test_get(struct HashMap *hm, char *key);

int main(void) {
    struct HashMap hm = {0};

    hash_map_insert(&hm, "pou", 2);
    hash_map_insert(&hm, "spongebob", 1);
    hash_map_insert(&hm, "crabb", 10);
    hash_map_insert(&hm, "something", 34);
    hash_map_insert(&hm, "abc", 10);
    hash_map_insert(&hm, "abc", 20);

    hash_map_println(&hm);

    test_get(&hm, "pou");
    test_get(&hm, "tpouueh");
    test_get(&hm, "something");

    return 0;
}

void test_get(struct HashMap *hm, char *key) {
    int out = 0;
    if (hash_map_get(hm, key, &out) != 0) {
        fprintf(stderr, "ITEM: %s NOT FOUND\n", key);
        return;
    }

    printf("key: %s, value: %d\n", key, out);
}
