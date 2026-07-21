#include "../../stack/stack.h"

#include <stdio.h>
#include <stdlib.h>

int fail = 0;

void test_push(Stack *s, const int val);
void test_print(Stack *s);
void test_pop(Stack *s);
void test_peek(Stack *s);
void test_clear(Stack *s);
void test_len(Stack *s);

int main(void) {
    Stack *s = stack_init(10);
    if (!s) {
        return EXIT_FAILURE;
    }

    test_push(s, 1);
    test_push(s, 2);
    test_push(NULL, 3);
    test_push(s, 4);

    test_print(s);

    test_pop(s);
    test_print(s);

    test_peek(s);
    test_print(s);

    test_clear(s);
    test_print(s);

    test_push(s, 1);
    test_push(s, 2);
    test_push(s, 3);
    test_push(s, 4);
    test_push(s, 5);

    test_print(s);

    test_len(s);

    stack_free(&s);

    return fail ? EXIT_FAILURE : EXIT_SUCCESS;
}

void test_push(Stack *s, const int val) {
    Stack_status status = STACK_OK;
    if ((status = stack_push(s, val)) != STACK_OK) {
        fail = 1;
        fprintf(stderr, "Error while pushing code: %d\n", status);
        return;
    }
}

void test_print(Stack *s) {
    Stack_status status = STACK_OK;
    if ((status = stack_println(s)) != STACK_OK) {
        fail = 1;
        fprintf(stderr, "Error while printing code: %d\n", status);
        return;
    }
}

void test_pop(Stack *s) {
    Stack_status status = STACK_OK;
    int out = 0;
    if ((status = stack_pop(s, &out)) != STACK_OK) {
        fail = 1;
        fprintf(stderr, "Error while popping code: %d\n", status);
        return;
    }

    printf("pop out: %d\n", out);
}

void test_peek(Stack *s) {
    Stack_status status = STACK_OK;
    int out = 0;
    if ((status = stack_top(s, &out)) != STACK_OK) {
        fail = 1;
        fprintf(stderr, "Error while peeking code: %d\n", status);
        return;
    }

    printf("top out: %d\n", out);
}

void test_clear(Stack *s) {
    Stack_status status = STACK_OK;
    if ((status = stack_clear(s)) != STACK_OK) {
        fail = 1;
        fprintf(stderr, "Error while clearing code: %d\n", status);
        return;
    }
}

void test_len(Stack *s) {
    size_t len = stack_len(s);
    printf("len %zu\n", len);
}
