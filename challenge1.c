#include "lib/hex_functions.h"
#include "lib/base64_functions.h"

int main(int argc, char **argv)
{
	unsigned char *hex_str = (unsigned char *) argv[1];
	
	unsigned char *bin_str; 
	unsigned char *result; 
	
	int len = strlen(hex_str); 

	printf("Converting hex to bin...\n"); 
	len = convert_hex_to_bin(&bin_str, hex_str, len); 

	printf("Converting bin to base64...\n"); 
	len = convert_bin_to_base64(&result, bin_str, len); 
	
	printf("Printing...\n"); 

	int i; 
	
	printf("Len: %i\n", len);  

	for(i = 0; i < len; i++)
	{
		printf("%c", result[i]); 
	}

	printf("\n"); 

}
