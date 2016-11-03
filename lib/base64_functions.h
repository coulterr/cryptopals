#ifndef BASE64_FUNCTIONS_H
#define BASE64_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int base64_to_bin(unsigned char *str, int len);
int bin_to_base64(unsigned char *str, int len);
int reduce_from_base64(unsigned char **dest, unsigned char *str, int len);
int expand_for_base64(unsigned char **dest, unsigned char *str, int len);
int convert_base64_to_bin(unsigned char **dest, unsigned char *str, int len);
int convert_bin_to_base64(unsigned char **dest, unsigned char *str, int len);

#endif









