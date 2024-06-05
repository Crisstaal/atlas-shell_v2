#include "ashv2.h"

/**
 * shell_cd - Changes the current directory
 * @args: List of arguments
 *
 * Return: 1 to continue executing
 */
int shell_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
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
