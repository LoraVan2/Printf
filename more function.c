#include "main.h"

/**
 * print_hexa - Converts decimal numbers to hexa form
 * @args: The decimal to Converts
 *
 * Return: The amount of output written
 */
int print_hexa(int args)
{
	unsigned int num = args;
	char hex_num[32];
	int i = 0, count = 0;

	do {
		hex_num[i++] = "0123456789abcdef"[num % 16];
		num /= 16;
	} while (num > 0);

	while (i-- > 0)
	{
		putchar(hex_num[i]);
		count++;
	}

	return (count);
}

/**
 * print_binary - Converts decimal to binary
 * @args: The decimal to convert
 *
 * Return: The amount output written
 */
int print_binary(va_list args)
{
	unsigned int arg = va_arg(args, int);
	int i = 0, count = 0, j;
	char binary[32] = {0};
	char buffer[32];

	if (arg == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (arg > 0)
	{
		binary[i] = arg % 2;
		arg = arg / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		buffer[count] = binary[j] + '0';
		count++;
	}
	write(1, buffer, count);

	return (count);
}

/**
 * print_octal - Converts decimal to Octal
 * @args: The Decimal to convert
 *
 * Return: The amount of string printed
 */
int print_octal(int args)
{
	unsigned int num = args;
	char oct_num[32];
	int i = 0, count = 0;

	do {
		oct_num[i++] = "012345678"[num % 8];
		num /= 8;
	} while (num > 0);

	while (i-- > 0)
	{
		putchar(oct_num[i]);
		count++;
	}

	return (count);
}
