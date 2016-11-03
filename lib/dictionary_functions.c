#include "dictionary_functions.h"

char **get_dictionary()
{ 
	FILE *src = fopen(PATH , "r+"); 
	char **words = malloc(WORDCOUNT * sizeof(char *)); 
	int i; 
	for(i = 0; i < WORDCOUNT; i++)
	{
		words[i] = malloc(40 * sizeof(char));
		fscanf(src, "%s", words[i]);
	}
	fclose(src); 

	return words; 
}

int free_dictionary(char **dictionary)
{
	int i; 
	for(i = 0; i < WORDCOUNT; i++)
	{
		free(dictionary[i]); 
	}

	free(dictionary); 
}

int consists_of_valid_characters(char *str, int len){
	
	int i; 
	for(i  = 0; i < len; i++){
		if(str[i] < 0x0 || str[i] > 0x7f){
			return 0; 
		}
	}

	return 1; 
}

int contains_substring(char *str, char *substr)
{
	int len = strlen(str); 
	int sublen = strlen(substr); 
	
	int i, j;

	for(i = 0; i <= (len - sublen); i++)
	{
		if(memcmp((void *) (str + i), (void *) (substr), sublen) == 0){
			return 1; 
		}
	}

	return 0; 

}


int count_valid_words(char *str, int len, char **dictionary)
{
	int hits = 0; 

	int i; 
	for(i = 0; i < WORDCOUNT; i++)
	{
		if(contains_substring(str, dictionary[i])){
			hits++; 
		}
	}

	return hits; 

}

int get_most_good_message(char **messages, int msg_count, int msg_len, char **dictionary)
{
	int i, max, count, best; 
	
	best = 0; 
	max = 0; 

	for(i = 0; i < msg_count; i++)
	{
		if(consists_of_valid_characters(messages[i], msg_len)){
			count = count_valid_words(messages[i], msg_len, dictionary); 
			if(count > max){
				max = count; 
				best = i; 
			}
		}
	}

	return best; 	
}











