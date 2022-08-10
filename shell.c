#include "shell.h"

/**
 * main - a simple UNIX command line interpreter
 * @ac: argument count
 * @av: argument vector
 * @environ: pointer to environment variables
 *
 * Return: Always 0.
*/
int main(int ac, char **av, char **environ)
{
	int token_count, status = 0;
	ssize_t count = 0;
	size_t n;
	pid_t child_pid;
	char *copy, *delim = " \n", *buffer = NULL, **argv;

	(void)ac;
	(void)av;
	do {
	_putchar('$');
	_putchar(' ');
	count = getline(&buffer, &n, stdin);
	if (count == -1)
	{
		perror(NULL);
		return (1);
	}
	/* duplicate buffer */
	copy = copy_buffer(buffer);
	/* get the number of tokens inputted */
	token_count = tokenize(buffer, delim);
	/* allocate space for the number of tokens */
	argv = malloc(sizeof(char *) * token_count);
	if (argv == NULL)
		return (1);
	/* split buffer(copy) into an array of strings */
	argv = buff_split(copy, delim, token_count);
	/* Execution with execve function */
	/* TODO: Add Execution with execve function */
	/**
	child_pid = fork();
	if (child_pid == 0)
	{
		status = execve(argv[0], argv, environ);
		if (status == -1)
		{
			perror("Error");
			return (1);
		}
	} wait(NULL); **/
	} while (count != -1);
	return (0);
}

/***** STRLEN FUNCTION ******/
/**
 * _strlen - calculate the length of a string
 * @str: string
 *
 * Return: Length of the string.
*/
int _strlen(const char *str)
{
	int index = 0;

	while (str[index])
		index++;
	return (index);
}

/***** TOKENIZE FUNCTION *****/
/**
 * tokenize - splits user's input into string of tokens
 * @buffer: string to be tokenized
 * @delim: delimiter value
 *
 * Return: Number of tokens found.
*/
int tokenize(char *buffer, char *delim)
{
	int token_count;
	char *token;

	token = strtok(buffer, delim);
	token_count = 1;
	while (token)
	{
		token = strtok(NULL, delim);
		token_count++;
	}
	return (token_count);
}

/***** BUFFER SPLIT FUNCTION *****/
/**
 * buff_split - splits a buffer into array of tokens
 * @buffer: string to split
 * @delim: deliimiter value
 * @token_count: number of tokens to be splitted
 *
 * Return: an Array containing the splitted buffer
 */

/******************************************************/
/* TODO: Add buff_split function */
/**
char **buff_split(char *buffer, char *delim, int token_count)
{
	char *token, **argv;
	int index = 0;

	argv = malloc(sizeof(char *) * token_count);
	if (argv == NULL)
		return (NULL);
	token = strtok(buffer, delim);
	while (token)
	{
		argv[index] = malloc(sizeof(char) * _strlen(token));
		if (argv[index] == NULL)
		{
			free(argv[index]);
			free(argv);
			return (NULL);
		}
	>>>> This is a comment >>>> copy the content of token into argv array
		strcpy(argv[index], token);
		index++;
		/* get the next token
		token = strtok(NULL, delim);
	}
	argv[index] = NULL;
	return (argv);
}
**/
/****************************************************************/

/**
  * copy_buffer - copies content of buffer
  * @buffer: string to be copied
  *
  * Return: a pointer to the duplicated buffer
*/
char *copy_buffer(char *buffer)
{
	char *copy;

	copy = malloc(sizeof(char) * _strlen(buffer));
	if (copy == NULL)
		return (NULL);
	strcpy(copy, buffer);
	return (copy);
}
