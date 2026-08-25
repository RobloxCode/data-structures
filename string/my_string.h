#ifndef MY_STRING_H
#define MY_STRING_H
#include <stdlib.h>

/**
 * @brief Status codes returned by String operations
 */
typedef enum {
    STRING_OK /*< Operation completed successfully */,
    STRING_ERR_WRONG_PTR, /*< A NULL or invalid pointer was passed */
    STRING_ERR_REALLOC,   /*< Internall reallocation failed */
    STRING_ERR_OVERFLOW,  /*< Requested capacity/size would overflow */
} Str_status;

typedef struct {
    // starting point of the array
    char *items;

    // number of characters (not counting the \0)
    size_t length;

    // allocated memory
    size_t capacity;
} String;

/**
 * @brief Creates a String
 *
 * @param init_len Initial capacity
 *
 * @return Pointer to a Heap allocated String, user must free
 */
String *string_create(const size_t init_len);

/**
 * @brief Adds a character at the end of the String
 *
 * @param dst Pointer to String to add the character
 * @param src Character being added
 *
 * @return STRING_OK, on success
 * @return STRING_ERR_WRONG_PTR, on NULL pointer
 * @return STRING_ERR_OVERFLOW, on capacity being bigger than SIZE_MAX
 * @return STRING_ERR_REALLOC, on internall fail realloc
 */
Str_status string_append_char(String *dst, const char src);

/**
 * @brief Frees the memory of a String
 *
 * @param Double pointer to str, sets to NULL *str
 *
 * @return STRING_OK, on success
 * @return STRING_ERR_WRONG_PTR, on NULL pointer
 */
Str_status string_free(String **str);

/**
 * @brief Prints to stdout the characters that make up the str
 *
 * @param str Pointer to String
 *
 * @return STRING_OK, on success
 * @return STRING_ERR_WRONG_PTR, on NULL pointer
 */
Str_status string_println(const String *str);

/**
 * @brief Appends a char * to a String
 *
 * @param dst Pointer to the String
 * @param src char * being added
 *
 * @return STRING_OK, on success
 * @return STRING_ERR_WRONG_PTR, on NULL pointer
 * @return STRING_ERR_OVERFLOW, on capacity being bigger than SIZE_MAX
 * @return STRING_ERR_REALLOC, on internall fail realloc
 */
Str_status string_append_cstr(String *dst, const char *src);

/**
 * @brief Compares the characters of both str1 and str2 one by one
 *
 * @param str1 Pointer to String
 * @param str2 Pointer to String
 * @param result Pointer to integer, the integer will be set to 1 if the
 *               characters from the String's are all equal, 0 otherwise
 *
 * @return STRING_OK, on success
 * @return STRING_ERR_WRONG_PTR, on NULL pointer
 */
Str_status string_compare(const String *str1, const String *str2, int *result);

/**
 * @brief Returns the length of che characters in a given String
 *
 * @param str Pointer to String
 *
 * @return Number of characters stored
 */
size_t string_len(const String *str);

/**
 * @brief Clears, zero sets the String (just the first item of str->items)
 *
 * @param str Pointer to String
 *
 * @return STRING_OK, on success
 * @return STRING_ERR_WRONG_PTR, on NULL pointer
 */
Str_status tring_clear(String *str);

/**
 * @brief Turns a String into a c string, it is null terminated
 *
 * @param str Pointer to String
 *
 * @return pointer to a const c string
 */
const char *string_cstr(const String *str);

#endif
