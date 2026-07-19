#ifndef MY_STRING_H
#define MY_STRING_H
#include <stddef.h>

/**
 * @brief Dynamic String implementation
 */
typedef struct {
    size_t cap;   /* < Number of items the buffer can hold before realloc */

    size_t len;   /* < Actual number of items stored, this variable
                       does not include the null terimnator character */

    char items[]; /* < Buffer storing the elements */
} String;

/**
 * @brief Heap allocates String and its buffer
 *
 * @param cap Initial capacity
 *
 * @return Pointer to String
 *         NULL or cap 0 or error while internal malloc
 */
String *string_init(const size_t cap);

/**
 * @brief Frees String and sets the pointer to NULL
 *
 * @param str Double pointer to a String
 */
void string_deinit(String **str);

/**
 * @brief Prints contents of the String
 *
 * @param str Pointer to String
 */
void string_println(const String *str);

/**
 * @brief Adds a given character at the end of the String
 *
 * @param str Double pointer to String in case of resizing
 * @param c Character to be added at the end
 *
 * @return 0 on success
 *         1 on NULL pointer or error while internal realloc
 */
int string_append_char(String **str, const char c);

/**
 * @brief Adds a c string to the end of the String
 *
 * @param str Double pointer to String in case of resizing
 * @param cstr C string to be added
 *
 * @return 0 on success
 *         1 on NULL pointer or error while internal realloc
 */
int string_append(String **str, const char *cstr);

/**
 * @brief Turns a String into a char *
 *
 * @param str Pointer to String
 *
 * @return Pointer to the start of a char *, it has null terminator
 *         at the end
 */
const char *string_to_cstr(const String *str);

/**
 * @brief Retrieves the number of characters already stored
 *
 * @param str Pointer to String
 *
 * @return number of elements
 */
size_t string_len(const String *str);

/**
 * @brief Compares two Strings character by character
 *
 * @param str1 Pointer to String
 * @param str2 Pointer to String
 *
 * @return 0 on both strings being equal
 *         1 if they're different or NULL pointer
 */
int string_cmp(const String *str1, const String *str2);

/**
 * @brief Clears a String by setting the first elememnt in the buffer to \0
 *
 * @parma str Pointer to String
 */
void string_clear(String *str);

/**
 * @brief Copies the content from a source String to a destination String
 *
 * @parma dst Pointer to the destination String
 * @param src Pointer to the destination String
 *
 * @return 0 on success
 *         1 on wrong pointer or source being bigger than destination
 */
int string_copy(String *dst, const String *src);

/**
 * @brief Stores two given String's into a destination String
 *
 * @param dst Double pointer to String in case of resizing
 * @param str1 Pointer to String
 * @param str2 Poinetr to String
 *
 * @return 0 on success
 *         1 on NULL pointer or error while internal realloc
 */
int string_concat(String **dst, const String *str1, const String *str2);

/**
 * @brief Takes an array of ints and joins every element in the array
 *        being separated by a separator character
 *
 * @param str Pointer to String
 * @param arr Int arr
 * @param len Number of elements in the int arr
 * @param separator Character that will separate every character once joined
 *
 * @return 0 on success
 *         1 on NULL pointer or empty int arr
 */
int string_join_int_arr(String *str, const int *arr, const size_t len,
                        const char *separator);

/**
 * @brief Changes an old character for a new one
 *
 * @param str Pointer to String
 * @param oldchar Character to be replaced
 * @param newchar New character
 *
 * @return 0 on success
 *         1 on NULL pointer
 */
int string_replace_char(String *str, const char oldchar, char newchar);

#endif
