#include "../../hashmap/hashmap.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

void test_get(struct HashMap *hm, const char *key);
void test_update(struct HashMap *hm, const char *key, int val);

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

    test_update(&hm, "pou", 45);
    test_update(&hm, "something", 45);
    test_update(&hm, "non", 45);

    printf("count: %zu\n", hm.values_count);

    hash_map_deinit(&hm);

    return 0;
}

void test_get(struct HashMap *hm, const char *key) {
    int out = 0;
    if (hash_map_get(hm, key, &out) != 0) {
        fprintf(stderr, "ITEM: %s NOT FOUND\n", key);
        return;
    }

    printf("key: %s, value: %d\n", key, out);
}

void test_update(struct HashMap *hm, const char *key, int val) {
    if (hash_map_update(hm, key, val) != 0) {
        fprintf(stderr, "ITEM: %s NOT FOUND\n", key);
        return;
    }

    hash_map_println(hm);
}
