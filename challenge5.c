#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/hex_functions.h"
#include "lib/xor_functions.h"


int main(int argc, char **argv)
{
	int i, len, keylen, newlen; 

	unsigned char *msg; 
	unsigned char *key; 
	unsigned char *result; 
	
	msg = argv[1]; 
	len = strlen(msg); 

	key = argv[2]; 
	keylen = strlen(key); 

	repeating_xor_string_on_char(msg, key, len, keylen); 

	newlen = convert_bin_to_hex(&result, msg, len); 

	for(i = 0; i < newlen; i++)
	{
		printf("%c", result[i]); 
	}
	printf("\n"); 
}
