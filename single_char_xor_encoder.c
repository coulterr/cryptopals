#include <stdio.h>
#include <string.h>
#include "lib/xor_functions.h"
#include "lib/hex_functions.h"


int main (int argc, char **argv) 
{
	int i; 
	
	unsigned char *message = argv[1]; 
        unsigned char *key = argv[2]; 
	
	int len = strlen(message); 

	unsigned char *hex_message; 

	xor_string_on_char(message, *key, len);

	len = convert_bin_to_hex(&hex_message, message, len); 

	for(i = 0; i < len; i++)
	{
		if(hex_message[i] != 0){
			printf("%c", hex_message[i]); 
		}else{
			break;
		}
	}

	printf("\n"); 


}
