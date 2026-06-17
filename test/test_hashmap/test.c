#include "../../hashmap/hashmap.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
    struct HashMap hm = {0};

    hash_map_insert(&hm, "pou", 2);
    hash_map_insert(&hm, "spongebob", 1);
    hash_map_insert(&hm, "crabb", 10);
    hash_map_insert(&hm, "something", 34);
    hash_map_insert(&hm, "abc", 10);
    hash_map_insert(&hm, "xyz", 20);

    hash_map_println(&hm);

    printf("get with key: %s, val: %d\n", "pou", hash_map_get(&hm, "pou"));
    printf("get with key: %s, val: %d\n", "pou", hash_map_get(&hm, "tpouueh"));

    return 0;
}
