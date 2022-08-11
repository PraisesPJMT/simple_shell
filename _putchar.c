#include "shell.h"

/**
   * _putchar - prints a character
    * @c: character to print
     *
      * Return: a char
      */
int _putchar(char c)
{
		return (write(1, &c, 1));
