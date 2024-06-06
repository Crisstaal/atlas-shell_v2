#include "ashv2.h"

/**
 * shell_env - Prints environment vars
 * @args: List of args (not used)
 *
 * Return: 1 to continue executing
 */
int shell_env(char **args)
{
	char **env = environ;

	(void)args;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (1);
}
