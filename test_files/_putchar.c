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
