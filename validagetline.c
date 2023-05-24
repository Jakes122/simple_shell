#include "main.h"
/**
 * validagetline - executes command lines entered by pipe
 * @len: length
 * @arg: argument1
 * @env_arg: Environmentarguments
 * Return: 0
 */
void validagetline(char *buffer, int len, char **args, char **env_args)
{
	if (len == EOF)
	{
		printf("salida EOF\n");
		write(STDOUT_FILENO, "\n", 1);
		if (buffer != NULL)
		{
			freedom(1, buffer);
			buffer = NULL;
		}
		if (args != NULL)
		{
			freedom(2, args);
			args = NULL;
		}
		if (env_args != NULL)
		{
			freedom(2, env_args);
			env_args = NULL;
		}
		exit(0);
	}
}
