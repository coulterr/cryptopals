#ifndef HEX_FUNCTIONS_H
#define HEX_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hex_to_bin(unsigned char *str, int len);
int bin_to_hex(unsigned char *str, int len);
int reduce_from_hex(unsigned char **dest, unsigned char *str, int len);
int expand_for_hex(unsigned char **dest, unsigned char *str, int len);
int convert_hex_to_bin(unsigned char **dest, unsigned char *str, int len);
int convert_bin_to_hex(unsigned char **dest, unsigned char *str, int len);

#endif









