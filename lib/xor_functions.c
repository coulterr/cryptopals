#include "xor_functions.h"
#include <stdio.h>
int xor_equal_length_strings(unsigned char *str1, unsigned char *str2, int len)
{
	int i; 
	for(i = 0; i < len; i++)
	{
		str1[i] = str1[i] ^ str2[i]; 
	}
}

int xor_string_on_char(unsigned char *str, unsigned char key, int len)
{
	int i; 
	for(i = 0; i < len; i++)
	{
		str[i] = str[i] ^ key; 
	}
}

int repeating_xor_string_on_char(unsigned char *str, unsigned char *key, int len, int keylen)
{
	int i, j; 
	j = 0; 
	for(i = 0; i < len; i++)
	{
		str[i] = str[i] ^ key[j]; 
		
		if(j < (keylen - 1)){
			j++; 
		}else{
			j = 0; 
		}
	}
}
