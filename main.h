#ifndef FUNC_H
#define FUNC_H

/* Header Declrearation */
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

/* Main Function */
int _printf(char *fmt, ...);

/* Type function */
int print_char(va_list);
int print_int(va_list);
int print_string(va_list);
int print_binary(va_list);
int print_hexa(int args);
int print_octal(int args);
int (*get_op(char *s))(int args);

#endif
