#include "main.h"
/**
 * _printf - produces outputs according to a format
 *@case'c': format that prints Characters
 *@case's': format that prints a string
 *@case'%': format that pints percentage
 *@case'd': format thaat prints a decimal
 *@case'i': format that prints intigers
 *Return: the specified value to the calling function
 */
void _printf(char *format, ...)
{
    va_list args;
    va_start(args, format);
    int count = 0;

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
            case 'd':
            {
                char arg = va_arg(args, int);
                print_int(arg + '0');
                break;
            }/* 
            case 's':
            {
                char *arg = va_arg(args, char *);
                printf("%s", arg);
                break;
            } */
            case 'c':
            {
                char arg = va_arg(args, int );
                print_char(arg);
            }
                // add more cases for other types as needed
            }
        }
        else
        {
            print_char(format[i]);
        }
    }

    va_end(args);
}

int print_char(char g)
{
    return (write(1, &g, 1));
}

int print_int(char i)
{
    return (write(1, &i, 1));
}
