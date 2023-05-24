#include "shell.h"
/**
 * interactive - always return true if shell is in interactive mode
 * @info: the struct address
 *
 * Return: one if interactive mode, zero otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - check if char is a delimeter
 * @d: char to check
 * @delim: string delimeter
 * Return: one if true, zero if false
 */
int is_delim(char d, char *delim)
{
	while (*delim)
		if (*delim++ == d)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic char
 * @d: char to input
 * Return: one if char is alphabetic, 0 otherwise
 */

int _isalpha(int d)
{
	if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - then convert a string to an integer
 * @s: string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int b, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (b = 0; s[b] != '\0' && flag != 2; b++)
	{
		if (s[b] == '-')
			sign *= -1;

		if (s[b] >= '0' && s[b] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[b] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

