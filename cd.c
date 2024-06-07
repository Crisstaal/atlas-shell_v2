#include "ashv2.h"

/**
 * shell_cd - Changes the current directory
 * @args: List of arguments
 *
 * Return: 1 to continue executing
 */
int shell_cd(char **args)
{
	char *home = getenv("HOME");

	if (args[1] == NULL)
	{
		if (home == NULL)
		{
			fprintf(stderr, "hsh: HOME not set\n");
			return (1);
		}
		if (chdir(home) != 0)
		{
			perror("hsh");
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}
