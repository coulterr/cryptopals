#include "base64_functions.h"

int base64_to_bin(unsigned char *str, int len)
{
	int i; 
	for(i = 0; i < len; i++)
	{
		if(str[i] >= 0x41 && str[i] <= 0x5a){
			str[i] =  (unsigned char) str[i] - 0x41; 
		}else if(str[i] >= 0x61 && str[i] <= 0x7a){
			str[i] = (unsigned char) (str[i] - 0x61) + 0x1a; 
		}else if(str[i] >= 0x30 && str[i] <= 0x39){
			str[i] = (unsigned char) (str[i] - 0x30) + 0x34; 
		}else if(str[i] == 0x2b){
			str[i] = (unsigned char) 0x3e; 
		}else if(str[i] == 0x2f){
			str[i] = (unsigned char) 0x3f;
		}else{
			fprintf(stderr, "ERROR: in function base64_to_bin, encountered illegal value\n"); 
			exit(0); 
		}
	}
}


int bin_to_base64(unsigned char *str, int len)
{
	int i; 
	for(i = 0; i < len; i++)
	{
		if(str[i] >= 0x00 && str[i] <= 0x19){
			str[i] =  (unsigned char) (0x41 + str[i]); 
		}else if(str[i] >= 0x1a && str[i] <= 0x33){
			str[i] = (unsigned char) (0x61 + (str[i] - 0x1a)); 
		}else if(str[i] >= 0x34 && str[i] <= 0x3d){
			str[i] = (unsigned char) (0x30 + (str[i] - 0x34)); 
		}else if(str[i] == 0x3e){
			str[i] = (unsigned char) 0x2b; 
		}else if(str[i] == 0x3f){
			str[i] = (unsigned char) 0x2f;
		}else{
			fprintf(stderr, "ERROR: in function bin_to_base64, encountered illegal value\n"); 
			exit(0); 
		}
	}
}


int reduce_from_base64(unsigned char **dest, unsigned char *str, int len)
{
	int i, j;
	int newlen = (len / 4) * 3;  
	*dest = malloc(newlen * sizeof(char)); 

	j = 0; 
	for(i = 0; i < len; i += 4)
	{
		unsigned char one, two, three, four;
		unsigned char temp1, temp2; 

		one = str[i]; 
		two = str[i + 1]; 
		three = str[i + 2]; 
		four = str[i + 3]; 
	
		temp1 = one; 
		temp1 = temp1 << 2; 
		temp2 = two; 
		temp2 = temp2 & 0x30;
		temp2 = temp2 >> 4; 
		(*dest)[j] = (temp1 | temp2); 
		j++; 

		temp1 = two; 
		temp1 = temp1 & 0x0f; 
		temp1 = temp1 << 4; 
		temp2 = three; 
		temp2 = temp2 & 0x3c; 
		temp2 = temp2 >> 2; 
		(*dest)[j] = (temp1 | temp2); 
		j++; 

		temp1 = three; 
		temp1 = temp1 & 0x03;
		temp1 = temp1 << 6; 
		temp2 = four; 
		(*dest)[j] = (temp1 | temp2); 
		j++; 
	}

	return newlen;  
}
	
int expand_for_base64(unsigned char **dest, unsigned char *str, int len)
{
	int i, j, newlen; 

	newlen = (len / 3) * 4; 
	*dest = malloc(newlen * sizeof(char)); 

	j = 0; 

	for(i = 0; i < len; i += 3)
	{
		unsigned char first, second, third; 
		unsigned char temp1, temp2; 
		first = str[i]; 
		second = str[i + 1];
		third = str[i + 2]; 

		temp1 = first; 
		temp1 = temp1 & 0xfc; 
		temp1 = temp1 >> 2; 
		(*dest)[j] = temp1; 
		j++; 

		temp1 = first; 
		temp1 = temp1 & 0x03; 
		temp1 = temp1 << 4; 
		temp2 = second;
		temp2 = temp2 & 0xf0; 
		temp2 = temp2 >> 4; 
		(*dest)[j] = (temp1 | temp2); 
		j++; 

		temp1 = second;
		temp1 = temp1 & 0x0f; 
		temp1 = temp1 << 2; 
		temp2 = third;
		temp2 = temp2 & 0xc0; 
		temp2 = temp2 >> 6;
		(*dest)[j] = (temp1 | temp2); 
		j++; 
		
		temp1 = third;
		temp1 = temp1 & 0x3f;
		(*dest)[j] = temp1; 
		j++; 
	}

	return newlen; 
}

int convert_base64_to_bin(unsigned char **dest, unsigned char *str, int len)
{
	int i, j, newlen, start_index;

	unsigned char *temp1;
	unsigned char *temp2; 


	if((len % 4) == 0){
		temp1 = malloc(len); 
		memcpy((void *) temp1, (void *) str, len); 
		newlen = len; 
	}else if((len % 4) == 3){
		temp1 = malloc(len + 1); 
		temp1[0] = 0x41; 
		memcpy((void *) (temp1 + 1), (void *) str, len); 
		newlen = len + 1;
	}else if((len % 4) == 2){
		temp1 = malloc(len + 2); 
		temp1[0] = 0x41;
		temp1[1] = 0x41; 
		memcpy((void *) (temp1 + 2), (void *) str, len); 
		newlen = len + 2; 
	}else if((len % 4) == 1){
		temp1 = malloc(len + 3); 
		temp1[0] = 0x41; 
		temp1[1] = 0x41;
		temp1[2] = 0x41;
		memcpy((void *) (temp1 + 3), (void *) str, len); 
		newlen = len + 3; 
	}

	base64_to_bin(temp1, newlen); 

	newlen = reduce_from_base64(&temp2, temp1, newlen); 
	
	start_index = 0; 
	j = newlen; 

	for(i = 0; i < j; i++){
		if(temp2[i] == 0x00){
			start_index++; 
			newlen--; 
		}else{
			break; 
		}
	}

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



int convert_bin_to_base64(unsigned char **dest, unsigned char *str, int len)
{
	int i, j, newlen, start_index;
	unsigned char *temp1;
	unsigned char *temp2; 

	
	if((len % 3) == 0){
		temp1 = malloc(len); 
		memcpy((void *) temp1, (void *) str, len); 
		newlen = len; 
	}else if((len % 3) == 2){
		temp1 = malloc(len + 1); 
		temp1[0] = 0x00;
		memcpy((void *) (temp1 + 1), (void *) str, len); 
		newlen = len + 1; 
	}else if((len % 3) == 1){
		temp1 = malloc(len + 2); 
		temp1[0] = 0x00; 
		temp1[1] = 0x00;
		memcpy((void *) (temp1 + 2), (void *) str, len); 
		newlen = len + 2; 
	}

	newlen = expand_for_base64(&temp2, temp1, newlen); 

	bin_to_base64(temp2, newlen); 

	start_index = 0;
	j = newlen; 

	for(i = 0; i < j; i++){
		if(temp2[i] == 0x41){
			start_index++; 
			newlen--; 
		}else{
			break; 
		}
	}

	if(newlen == 0){
		newlen++; 
		*dest = malloc(newlen); 
		(*dest)[0] = 0x41; 
	}else{
		*dest = malloc(newlen); 
		memcpy((void *) (*dest), (void *) (temp2 + start_index), newlen); 
	}

	free(temp2); 
	free(temp1);

	return newlen; 
}

