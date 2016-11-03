#ifndef XOR_FUNCTIONS_H
#define XOR_FUNCTIONS_H

int xor_equal_length_strings(unsigned char *str1, unsigned char *str2, int len);
int xor_string_on_char(unsigned char *str, unsigned char key, int len); 
int repeating_xor_string_on_char(unsigned char *str, unsigned char *key, int len, int keylen); 

#endif
