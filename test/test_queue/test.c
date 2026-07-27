#include "../../queue/queue.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Queue *q = queue_init();
    if (!q) {
        return EXIT_FAILURE;
    }

    queue_deinit(&q);

    return EXIT_SUCCESS;
}
