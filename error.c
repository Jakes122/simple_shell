#include "main.h"

/**
 * error_msg - it writes the error message
 * @args: command to be executed
 * Return: nothing
 */

void error_msg(char **args)
{
	int loop = 1;
	char *hsh_home = "";
	char *looper = NULL;
	char *error_message = malloc(sizeof(char) * 255);

	looper = int_to_charac(loop);
	error_message = strduplicate(hsh_home);
	error_message = strconk(error_message, ": ");
	error_message = strconk(error_message, ": ");
	error_message = strconk(error_message, args[0]);
	error_message = strconk(error_message, looper);
	perror(error_message);
	free(error_message);
}

/**
 * error_badcommand - error deppends on error num
 * Return: nothing
 */
void error_badcommand(char **args, char *buffer)
{
	write(STDOUT_FILENO, "command not found\n", 18);
	freedom(1, buffer);
	buffer = NULL;
	freedom(2, args);
	args = NULL;
}
