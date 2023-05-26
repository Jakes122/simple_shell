#include "shell.h"

/**
 * bfree - NULLS ADDRESS
 * @ptr: address of the pointer to free
 * Return: 1 freed, 0 otherwise
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
