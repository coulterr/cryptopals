#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib/hex_functions.h"
#include "lib/dictionary_functions.h"
#include "lib/cipher_functions.h"
int main(int argc, char **argv)
{
	int i, hexlen, binlen; 

	unsigned char *hex_str; 
	unsigned char *bin_str; 
	unsigned char *result; 
	char **dictionary; 
	unsigned char key; 

	hex_str = argv[1]; 
	hexlen = strlen(hex_str); 

	binlen = convert_hex_to_bin(&bin_str, hex_str, hexlen); 

	dictionary = get_dictionary(); 

	result = malloc(binlen); 

	key = get_deciphered_single_char_xored_string(result, bin_str, binlen, dictionary); 

	printf("Key: %c\n", key); 

	for(i = 0; i < binlen; i++)
	{
		printf("%c", result[i]); 
	}
	printf("\n"); 
}
