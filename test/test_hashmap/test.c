#include "../../hashmap/hashmap.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
    hash_insert("new", 2);
    hash_insert("1", 1);
    hash_println();
    printf("key: new, val: %d\n", hash_get("1"));
    return 0;
}
