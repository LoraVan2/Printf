#include "main.h"

/**
 * get_op - Function to get operations
 * @s: Pointer to Function
 * Return: Function
 */
int (*get_op(char *s))(int args)
{
	int i;
	_op ops[] = {
		{"b", print_hexa},
		{"o", print_octal},
		{"x", print_hexa},
		{"X", print_hexa},
		{"r", print_hexa},
		{NULL, NULL},
	};

	i = 0;
	while (ops[i].name != NULL && *(ops[i].name) != *s)
	{
		i++;
	}
	return (ops[i].func);
}
