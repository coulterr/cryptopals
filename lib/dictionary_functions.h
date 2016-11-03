#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef DICTIONARY_FUNCTIONS_H
#define DICTIONARY_FUNCTIONS_H

#define WORDCOUNT 109584
#define PATH "lib/data/words.txt"

char **get_dictionary(); 
int free_dictionary(char **dictionary); 
int consists_of_valid_characters(char *str, int len); 
int contains_substring(char *str, char *substr); 
int count_valid_words(char *str, int len, char **dictionary); 
int get_most_good_message(char **messages, int msg_count, int msg_len, char **dictionary);

#endif
