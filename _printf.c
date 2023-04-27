#include "main.h"

/**
 * _printf - Print formated text
 * @format: The text to be printed
 *
 * Return: The nuber of characters printed
 */
int _printf(char *format, ...)
{
	int times, i;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'i':
			case 'd':
				times += print_int(args);
				break;
			case 's':
				times += print_string(args);
				break;
			case 'c':
				times += print_char(args);
				break;
			case '%':
				times += write(1, "%", 1);
				break;
			case 'b':
				times += print_binary(args);
				break;
			default:
				times += write(1, &format[i - 1], 2);
				break;
			}
		}
		else
			times += write(1, &format[i], 1);
	va_end(args);
	return (times);
}

/**
 * print_char - Prints the characters given
 * @args: va_list of the character to be printed
 *
 * Return: The amount of characters printed
 */
int print_char(va_list args)
{
	char arg = va_arg(args, int);

	return (write(1, &arg, 1));
}

/**
 * print_int - Print single integer characters
 * @args: va_list of the integer to be printed
 *
 * Return: The amount of integer printed out
 */
int print_int(va_list args)
{
	int arg = va_arg(args, int);
	char buffer[12];
	int count = 0, i = 0;
	int j, k;
	char temp;

	if (arg == 0)
	{
		count = 1;
		write(1, "0", 1);
		return (count);
	}
	if (arg < 0)
	{
		count += write(1, "-", 1);
		arg = -arg;
	}
	while (arg > 0)
	{
		buffer[i++] = (arg % 10) + '0';
		arg /= 10;
	}
	for (j = 0, k = i - 1; j < k; j++, k--)
	{
		temp = buffer[j];
		buffer[j] = buffer[k];
		buffer[k] = temp;
	}
	count += write(1, buffer, i);

	return (count);
}

/**
 * print_string - Prints string to stdout
 * @args: va_list of the string to be printed
 *
 * Return: The lenght of the string printed out
 */
int print_string(va_list args)
{
	int len;
	char *arg = va_arg(args, char *);

	len = strlen(arg);
	if (arg == NULL)
	{
		arg = "(null)";
		len = strlen(arg);
	}

	return (write(1, arg, len));
}
