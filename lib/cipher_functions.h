#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hex_functions.h"
#include "xor_functions.h"
#include "dictionary_functions.h"
#include "int_queue.h"
#ifndef CIPHER_FUNCTIONS_H
#define CIPHER_FUNCTIONS_H

unsigned char get_deciphered_single_char_xored_string(char *dest, char *str, int len, char **dictionary);
int get_char_hamming_dist(unsigned char char1, unsigned char char2);
int get_hamming_distance(unsigned char *str1, unsigned char *str2, int len);
int get_smallest_hamming(int_queue *keysizes, unsigned char *str, int min, int max);

#endif
