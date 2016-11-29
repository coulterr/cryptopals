#ifndef FILE_FUNCTIONS_H
#define FILE_FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int read_stripped_file_into_buffer(char *path, char *buffer);

#endif

