#include <string.h>
#include <stdio.h>
#include "lib/hex_functions.h"
#include "lib/xor_functions.h"

int main(int argc, char **argv)
{
	int i, hexlen, binlen; 

	unsigned char *hex_str1; 
	unsigned char *hex_str2; 
	unsigned char *bin_str1; 
	unsigned char *bin_str2;
	unsigned char *result; 

	hex_str1 = argv[1]; 
	hex_str2 = argv[2]; 

	hexlen = strlen(hex_str1); 
	
	binlen = convert_hex_to_bin(&bin_str1, hex_str1, hexlen); 
	binlen = convert_hex_to_bin(&bin_str2, hex_str2, hexlen); 

	xor_equal_length_strings(bin_str1, bin_str2, binlen);


	hexlen = convert_bin_to_hex(&result, bin_str1, binlen); 

	for(i = 0; i < hexlen; i++){
		printf("%c", result[i]); 
	}
	printf("\n"); 
	
	

}
