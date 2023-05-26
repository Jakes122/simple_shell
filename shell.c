#include "holberton.h"

/**
 * main - function that has an infinite loop
 * @av: nothing
 * @ac:nothing
 * Return: loop
 */
int main(int ac, char **av)
{
	(void)av;
	(void)ac;

	signal(SIGINT, controlC);
	prompt();
	return (0);
}
