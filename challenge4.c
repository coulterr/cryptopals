#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/hex_functions.h"
#include "lib/xor_functions.h"
#include "lib/dictionary_functions.h"
#include "lib/cipher_functions.h"

#define ENTRIES 327
#define LEN 60

int main(int argc, char **argv)
{
	int i, j, len, newlen;  
	char *path; 
	char **dictionary; 
	unsigned char *translated; 
	char **decoded_messages;
	char next[LEN]; 
	FILE *file; 

	if(argc < 2){
		fprintf(stderr, "ERROR: missing argument\n"); 
	}

	path = argv[1]; 

	dictionary = get_dictionary(); 

	decoded_messages = malloc(ENTRIES * sizeof(char *)); 
	file = fopen(path, "r+"); 

	i = 0; 
	
	while(i < ENTRIES)
	{
		fscanf(file, "%s", next);

		len = strlen(next); 
		if(len == 0) break; 
			
		newlen = convert_hex_to_bin(&translated, next, len); 
		decoded_messages[i] = malloc(newlen);	
		get_deciphered_single_char_xored_string(decoded_messages[i], translated, newlen, dictionary);  
	
		free(translated);

		i++; 
	}
	fclose(file); 

	int best_message_index = get_most_good_message(decoded_messages, ENTRIES, newlen, dictionary); 

	for(i = 0; i < newlen; i++)
	{
		printf("%c", decoded_messages[best_message_index][i]); 
	}

	printf("\n"); 

	for(i = 0; i < ENTRIES; i++)
	{
		free(decoded_messages[i]); 
	}

	free(decoded_messages); 

	free_dictionary(dictionary); 

}








