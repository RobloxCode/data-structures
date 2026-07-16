#include "../../slice/slice.h"

#include <stddef.h>

#define LEN(a) (sizeof(a) / sizeof(a[0]))

int main(void) {
    int buf[100];

    for (size_t i = 0; i < LEN(buf); ++i) {
        buf[i] = (int)i + 1;
    }

    intSlice slice;
    slice_init(&slice, buf, LEN(buf), 0, 50);

    slice_println(&slice);

    return 0;
}
