#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int read_stripped_file_into_buffer(char *buffer, char *path)
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
