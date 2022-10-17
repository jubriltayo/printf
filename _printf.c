#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>
/**
 * _printf - function that prints output to screen
 * @format: format specifier
 *
 * Return: int
 */

int _printf(const char *format, ...)
{
	int i;
	int result = 0;

	va_list args;

	va_start(args, format);

	/*accessing the format specifier*/

	for (i = 0; format[i] != '\0';)
	{
		/*Provided there is no '%' prefix, this prints each character out*/
		if (format[i] != '%')
		{
			result += _putchar(format[i]);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] != ' ')
		{
			case 'c':
			result += _putchar(va_arg(args, int));
			break;
			case 's':
			result += print_strings(va_arg(args, char *));
			break;
			case '%':
			result += _putchar('%');
			break;
			default:
			break;
		}
		i += 2;   /*jump out of the specifier*/
	}
	va_end(args);
	return (result);
}

/* _putchar */
#include <unistd.h>

/**
 * _putchar - prints out a character
 * @c: character
 *
 * Return: int
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_strings - prints strings
 * @string: string to print
 * Return: int
 */

int print_strings(char *string)
{
	int i;
	int total = 0;

	for (i = 0; string[i] != '\0'; i++)
		total = total + _putchar(string[i]);

	return (total);
}

/**
 * print_decimal - prints decimal
 * @num: number to print
 * Return: int
 */
int print_decimal(int num)
{
	int result = 0;

	/*if number is negative */
	if (num < 0)
	{
		result += _putchar('-');
		num = num * -1;
	}
	/**
	 * print numbers using recursion by removing last digits and
	 * print the remaining, then finally print the last digit
	 * /
	if (num / 10)
	{
		result += print_decimal(num / 10);
	}
	result += _putchar(num % 10 + '0');
	return (result);
}
