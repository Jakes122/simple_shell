#include "main.h"
/**
 * free_env - frees th user arguments
 * @args: user commands
 * Return: 0
 */

void free_env(char **env_args, char **args)
{
	if (env_args != NULL)
	{
		freedom(2, env_args);
	}
	freedom(2, args);
}
