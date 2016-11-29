#include "file_functions.h"

int read_stripped_file_into_buffer(char *path, char *buffer)
{
	int i, len, status; 
	unsigned char nextchar; 
	
	FILE *file = fopen(path, "r+"); 
	 
	len = 0; 
	
	do{
		nextchar = (unsigned char) fgetc(file); 
		if( (int) nextchar != EOF && nextchar != '\n' && nextchar != '='){
			buffer[len] = nextchar; 
			len++; 
		}
	}while(nextchar != '=');
	

	fclose(file); 

	return len; 
}
