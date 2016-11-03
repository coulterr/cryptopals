#include "hex_functions.h"

int hex_to_bin(unsigned char *str, int len)
{
	int i; 
	for(i = 0; i < len; i++)
	{
		if(str[i] >= 0x30 && str[i] <= 0x39){
			str[i] = str[i] - 0x30; 
		}else if(str[i] >= 0x61 && str[i] <= 0x66){
			str[i] = (str[i] - 0x61) + 0x0a; 
		}else{
			fprintf(stderr, "ERROR: in function hex_to_bin, encountered illegal value\n"); 
			exit(0); 
		}
	}
}


int bin_to_hex(unsigned char *str, int len)
{
	int i; 
	for(i = 0; i < len; i++)
	{
		if(str[i] >= 0x00 && str[i] <= 0x09){
			str[i] = str[i] + 0x30; 
		}else if(str[i] >= 0x0a && str[i] <= 0x0f){
			str[i] = (str[i] - 0x0a) + 0x61; 
		}else{
			fprintf(stderr, "ERROR: in function bin_to_hex, encountered illegal value\n"); 
			exit(0); 
		}
	}
}

int reduce_from_hex(unsigned char **dest, unsigned char *str, int len)
{
	int i, j;
	int newlen = len / 2;  
	*dest = malloc((newlen) * sizeof(char)); 

	j = 0; 
	for(i = 0; i < len; i+=2)
	{
		unsigned char first, second; 
		
		first = str[i]; 
		second = str[i + 1]; 
		
		first = first << 4; 
		(*dest)[j] = (first | second); 
		j++; 
	}

	return newlen;  
}
	
int expand_for_hex(unsigned char **dest, unsigned char *str, int len)
{
	int newlen = len * 2; 
	*dest = malloc((newlen) * sizeof(char)); 

	int i, j; 
	j = 0; 

	for(i = 0; i < len; i++)
	{
		unsigned char first = str[i]; 
		unsigned char second = str[i]; 

		first = first & 0xf0; 
		first = first >> 4; 
		second = second & 0xf; 

		(*dest)[j] = first; 
		j++; 
		(*dest)[j] = second; 
		j++;
	}

	return newlen; 
}

int convert_hex_to_bin(unsigned char **dest, unsigned char *str, int len)
{
	int i, j, newlen, start_index;

	unsigned char *temp1;
	unsigned char *temp2; 

	hex_to_bin(str, len);

	if(len % 2 == 1){
		temp1 = malloc(len + 1);
		temp1[0] = 0x00; 
		memcpy((void *) temp1 + 1, (void *) str, len); 
		len++; 
	}else{
		temp1 = malloc(len); 
		memcpy((void *) temp1, (void *) str, len); 
	}

	newlen = reduce_from_hex(&temp2, temp1, len); 
	
	start_index = 0; 
	j = newlen; 
	
	for(i = 0; i < j; i++){
		if(temp2[i] == 0x00){
			start_index++; 
			newlen--; 
		}else{
			break; 
		}}

	if(newlen == 0){
		newlen++; 
		*dest = malloc(newlen); 
		(*dest)[0] = 0x00; 
	}else{
		*dest = malloc(newlen); 
		memcpy((void *)(*dest), (void *) (temp2 + start_index), newlen); 
	}
	
	free(temp1);
	free(temp2); 


	return newlen; 
}



int convert_bin_to_hex(unsigned char **dest, unsigned char *str, int len)
{
	int i, j, newlen, start_index;
	unsigned char *temp1;

	newlen = expand_for_hex(&temp1, str, len); 

	bin_to_hex(temp1, newlen); 
	
	start_index = 0; 
	j = newlen; 

	for(i = 0; i < j; i++){
		if(temp1[i] == 0x30){
			start_index++; 
			newlen--; 
		}else{
			break; 
		}
	}

	if(newlen == 0){
		newlen++; 
		*dest = malloc(newlen); 
		(*dest)[0] = 0x30; 
	}else{
		*dest = malloc(newlen); 
		memcpy((void *) (*dest), (void *) (temp1 + start_index), newlen); 
	}

	free(temp1);

	return newlen; 
}

