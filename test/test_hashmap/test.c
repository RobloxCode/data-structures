#include "../../hashmap/hashmap.h"

#include <stddef.h>
#include <stdint.h>

int main(void) {
    hash_insert("pou", 2);
    hash_insert("pou", 3);
    hash_insert("spongebob", 1);
    hash_insert("spongebob", 2); // simulating collitions
    hash_insert("crabb", 10);
    hash_insert("something", 34);
    hash_insert("something", 4);
    hash_insert("abc", 10);
    hash_insert("xyz", 20);

    hash_println();
    return 0;
}
