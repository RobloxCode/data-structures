#include "../../string/my_string.h"

#include <stdio.h>
#include <stdlib.h>

#define ASSERT_MSG(cond, ...)                                                  \
    do {                                                                       \
        if (!(cond)) {                                                         \
            fprintf(stderr,                                                    \
                    "Assertion failed: (%s), file %s, line %d: ", #cond,       \
                    __FILE__, __LINE__);                                       \
            fprintf(stderr, __VA_ARGS__);                                      \
            fprintf(stderr, "\n");                                             \
            abort();                                                           \
        }                                                                      \
    } while (0)

int main(void) {
    String *str = string_create(10);

    ASSERT_MSG(str != NULL, "error creating String");

    ASSERT_MSG(string_println(str) != STRING_OK, "error when printing");

    ASSERT_MSG(string_append_cstr(str, "hello") != STRING_OK,
               "error when appending");
    ASSERT_MSG(string_println(str) != STRING_OK, "error when printing");
    ASSERT_MSG(string_append_cstr(str, " how are you") != STRING_OK,
               "error when appending");

    ASSERT_MSG(string_append_char(str, 'e') != STRING_OK,
               "error when appending character");
    ASSERT_MSG(string_println(str) != STRING_OK, "error when printing");

    printf("len: %zu\n", string_len(str));

    ASSERT_MSG(string_free(&str) != STRING_OK, "error when freeing");
}
