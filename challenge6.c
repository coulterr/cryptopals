#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib/cipher_functions.h"

int main(int argc, char **argv)
{
	int len, hamming; 

	unsigned char *str1; 
	unsigned char *str2;
	
	str1 = argv[1]; 
	str2 = argv[2]; 

	len = strlen(str1); 

	hamming = get_hamming_distance(str1, str2, len); 

	printf("Hamming Distance %d\n", hamming); 

}
