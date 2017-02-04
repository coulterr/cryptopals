#include <string.h>
#include <stdio.h>
#include "lib/hex_functions.h"
#include "lib/xor_functions.h"
#include "lib/cipher_functions.h"
#include "lib/dictionary_functions.h"

int main (int argc, char **argv)
{
	unsigned char *message = argv[1];
	int len = strlen(message); 
	
	unsigned char *dest; 
	len = convert_hex_to_bin(&dest, message, len); 


	char **dictionary = get_dictionary(); 
	char *result = malloc(len); 


	get_deciphered_single_char_xored_string(result, dest, len, dictionary); 

	int i; 

	for(i = 0; i < len; i++)
	{	
		printf("%c", result[i]); 
	}
	printf("\n"); 


}
