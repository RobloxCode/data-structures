#include "../../string_flexarrmem/my_string.h"

#include <stdio.h>
#include <stdlib.h>

int fail = 0;

int main(void) {
    String *s = string_init(10);
    if (!s) {
        return EXIT_FAILURE;
    }

    string_append(&s, "appending text");
    string_append(&s, " appending text again to grow capaci");

    string_println(s);

    string_append_char(&s, 't');
    string_append_char(&s, 'y');

    string_println(s);

    string_deinit(&s);

    return fail ? EXIT_FAILURE : EXIT_SUCCESS;
}
