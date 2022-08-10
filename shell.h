#ifndef PID_H
#define PID_H

/* Standard Libraries */
/* TODO: Add all the standard Libraries */
/* They are: */
/**
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>

Just remove the unnecessary comments.
 */

/* FUNCTION PROTOTYPES */
int _putchar(char c);
int _strlen(const char *str);
int tokenize(char *buffer, char *delim);
char **buff_split(char *buffer, char *delim, int token_count);
char *copy_buffer(char *buffer);

#endif
