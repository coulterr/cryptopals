#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib/file_functions.h"
#include "lib/cipher_functions.h"

typedef struct{
	int length; 
	unsigned char *buffer; 
}block; 


int main(int argc, char **argv)
{
	int i, j, k, len, keysize; 

	char *path = argv[1]; 
	unsigned char *ciphertext = malloc(10000);
	
	len = read_stripped_file_into_buffer(path, ciphertext); 
	printf("len: %d\n", len);  

	int_queue keysizes; 
	int_queue_init(&keysizes); 
	
	get_smallest_hamming(&keysizes, ciphertext, 2, 40); 

	
	printf("Printing Cipertext:\n"); 

	for(i = 0; i < len; i++)
	{
		printf("%c ", ciphertext[i]); 
	}

	printf("\n"); 

	
	char result[len]; 
		
	int number_of_keysizes = keysizes.size; 

	for(i = 0; i < number_of_keysizes; i++)
	{
		int keysize = int_dequeue(&keysizes); 
		
		block blocks[keysize];  

		for(j = 0; j < keysize; j++)
		{
			blocks[j].length = 0; 
			blocks[j].buffer = (unsigned char *) malloc(len / keysize); 
		}

		for(j = 0; j < len; j++)
		{
			blocks[j % keysize].buffer[blocks[j % keysize].length] = ciphertext[j]; 
			blocks[j % keysize].length++; 
		}
	
		printf("Printing for keysize %d: \n", keysize); 

		for(j = 0; j < keysize; j++)
		{
			for(k = 0; k < blocks[j].length; k++)
			{
				printf("%c ,", blocks[j].buffer[k]); 
			}
			printf("\n\n"); 
		}

		int key; 

		for(j = 0; j < keysize; j++)
		{
			char dest[blocks[j].length]; 

			//DO SOMETHING WITH BLOCKS[j].BUFFER 	

			for(k = 0; k < blocks[j].length; k++)
			{
				result[k * keysize + j] = dest[k]; 
			}

			
			printf("Key: %c\n", (unsigned char) key); 
		}
					
		printf("Final Result!:\n"); 
	
		printf("Keylen: %d\n", keysize); 

		for(j = 0; j < len; j++)
		{
			printf("%c", result[j]); 
		}

		printf("\n"); 
	}

}



