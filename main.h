#ifndef FUNC_H
#define FUNC_H

/* prototypes to be used in printing in printf program */
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>

/**
 * struct _operation - struct _operation
 * @name: _operation name
 * @func: _operation fucntion
 */
typedef struct _operation
{
	char *name;
	int (*func)(int argument);
} _op;

/* function prints formatted txt */
int _printf(char *fmt, ...);

/**
 * print_char - prints characters
 * print_int - prints integers
 * print_string - prints string of characters
 * print_binary - prints decimals
 * print_hexa - convert decimal to hexadecimal
 * print_octal - prints octal numbers
 * get_opt - function to get operations
 */
int print_char(va_list);
int print_int(va_list);
int print_string(va_list);
int print_binary(va_list);
int print_hexa(int args);
int print_octal(int args);
int (*get_op(char *s))(int args);

#endif
