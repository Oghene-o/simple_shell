#include "shell.h"
/**
 **_strncpy - extract a string
 *@dest: destination string to be extracted to
 *@src:  source string
 *@n:  amount of chars to be extracted
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int z, j;
	char *s = dest;

	z = 0;
	while (src[z] != '\0' && z < n - 1)
	{
		dest[z] = src[z];
		z++;
	}
	if (z < n)
	{
		j = z;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - to concatenates two strings
 *@dest: first string
 *@src:  second string
 *@n:  amount of bytes to be maximally used
 *Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int z, j;
	char *s = dest;

	z = 0;
	j = 0;
	while (dest[z] != '\0')
		z++;
	while (src[j] != '\0' && j < n)
	{
		dest[z] = src[j];
		z++;
		j++;
	}
	if (j < n)
		dest[z] = '\0';
	return (s);
}

/**
 **_strchr - to locate a char in a string
 *@s: the string to be parsed
 *@c: the char to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

