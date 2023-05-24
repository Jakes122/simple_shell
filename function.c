#include <stdio.h>

/**
 * _compare - compares two strings
 * @y: one string
 * @x: other string
 * Return: 0
 */
int _compare(char *x, char *y)
{
	while (*x && *y)
	{
		if (*x != *y)
			return (0);

		x++;
		y++;
	}

	return (*y == '\0');
}

/**
 * _strstr - Compares the two strings at a given part
 * Return: the pointer to the first occurence
 */
char *_strstr(char *x, char *y)
{
	while (*x != '\0')
	{
		if ((*x == *y) && _compare(x, y))
			return (x);
		x++;
	}

	return (NULL);
}

/**
 * _strcpy - copies a string pointed by the src
 * @src: _char
 * @dest: char
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0, j;

	while (src[i] != '\0')
	{
		i++;
	}
	for (j = 0; j <= i; j++)
	{
		dest[j] = src[j];
	}
	return (dest);
}
