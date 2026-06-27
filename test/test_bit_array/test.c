#include "../../bit_array/bit_array.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int fail = 0;

void test_get(struct u8_BitArr *ba, int pos);
void test_set(struct u8_BitArr *ba, int pos);

int main(void) {
    unsigned int items = 0b10010010;
    struct u8_BitArr byte = {.items = items};

    u8_bit_arr_print(&byte);

    test_get(&byte, 0);
    test_get(&byte, 4);
    test_get(&byte, 8);
    test_get(&byte, 7);

    test_set(&byte, 0);
    test_set(&byte, 1);
    test_set(&byte, 2);

    u8_bit_arr_print(&byte);

    return fail ? EXIT_FAILURE : EXIT_SUCCESS;
}

void test_get(struct u8_BitArr *ba, int pos) {
    int bit = 0;
    int status = 0;

    if ((status = u8_bit_arr_get(ba, pos, &bit)) != 0) {
        fprintf(stderr, "ERROR status: %d\n", status);
        fail = 1;
    }

    printf("item at position: %d is: %d\n", pos, bit);
}

void test_set(struct u8_BitArr *ba, int pos) {
    int status = 0;

    if ((status = u8_bit_arr_set(ba, pos)) != 0) {
        fprintf(stderr, "ERROR status: %d\n", status);
        fail = 1;
    }

    printf("you set the position: %d\n", pos);
}
