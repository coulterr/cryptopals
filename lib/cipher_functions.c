#include "cipher_functions.h"


unsigned char get_deciphered_single_char_xored_string(char *dest, char *str, int len, char **dictionary)
{
	int i;    
	
	char **decoded_strings = malloc(256 * sizeof(char *));

	for(i = 0; i < 256; i++)
	{
		decoded_strings[i] = malloc(len * sizeof(char)); 
		memcpy((void *) decoded_strings[i], (void *) str, len); 
		xor_string_on_char(decoded_strings[i], (unsigned char) i, len); 
	}

	int best_index = get_most_good_message(decoded_strings, 256, len, dictionary); 

	memcpy((void *) dest, (void *) decoded_strings[best_index], len); 

	for(i = 0; i < 256; i++){
		free(decoded_strings[i]); 
	}

	free(decoded_strings); 

	return (unsigned char) best_index;  
}

int get_char_hamming_dist(unsigned char char1, unsigned char char2)
{
	int count = 0; 

	unsigned char xored_char = (char1 ^ char2);
	
	if(xored_char & 0x80){
		count++;
	} 
	if(xored_char & 0x40){
		count++;
	}
	if(xored_char & 0x20){
		count++;
	} 
	if(xored_char & 0x10){
		count++;
	}
	if(xored_char & 0x08){
		count++;
	} 
	if(xored_char & 0x04){
		count++;
	}
	if(xored_char & 0x02){
		count++;
	} 
	if(xored_char & 0x01){
		count++;
	}

	return count; 

}

int get_hamming_distance(unsigned char *str1, unsigned char *str2, int len)
{
	int i, count; 

	count = 0;
	
	for(i = 0; i < len; i++)
	{
		count += get_char_hamming_dist(str1[i], str2[i]); 
	}

	return count; 
}


int get_smallest_hamming(int_queue *keysizes, unsigned char *str, int min, int max)
{
	int i, dist, smallest;
	smallest = 1000; 

	for(i = min; i < max; i++)
	{
		dist = get_hamming_distance(str, str + i, i); 
		
		if(dist <= smallest){
			int_enqueue(keysizes, i); 
		}
	}
}













