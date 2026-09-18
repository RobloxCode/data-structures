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

    string_free(&str);
}
