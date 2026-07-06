#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

/**
 * @brief an array of 8 bits, all stored in the same int variable
 * @var items Buffer for the 8 bits
 */
struct u8_BitArr {
    unsigned int items : 8;
} __attribute__((packed));

/**
 * @brief Takes an 8 bit char and prints it as binary
 *
 * @param num Number to print as binary
 */
void print_bin(const unsigned char num);

/**
 * @brief Displays the bits in the u8_BitArr struct
 *
 * @param ba Pointer to a u8_BitArr
 * @return 1 an NULL pointer
 *         0 on success
 */
int u8_bit_arr_print(const struct u8_BitArr *ba);

/**
 * @brief Sets to 1 the bit at the n position
 *
 * @param ba Pointer to a u8_BitArr
 * @param n Position to be set to 1
 * @return 1 an NULL pointer or n greater than 7
 *         0 on success
 */
int u8_bit_arr_set(struct u8_BitArr *ba, int n);

/**
 * @brief Sets to 0 the bit at the n position
 *
 * @param ba Pointer to a u8_BitArr
 * @param n Position to be set to 0
 * @return 1 an NULL pointer or n greater than 7
 *         0 on success
 */
int u8_bit_arr_clear(struct u8_BitArr *ba, int n);


/**
 * @brief stores the value at the ith position in the out variable
 *
 * @param ba Pointer to a u8_BitArr
 * @param i Numbor of the position to be retrieved
 * @param out Pointer to a buffer for the result
 * @return 1 an NULL pointer or i greater than 7
 *         0 on success
 */
int u8_bit_arr_get(const struct u8_BitArr *ba, const int i, int *out);

#endif
