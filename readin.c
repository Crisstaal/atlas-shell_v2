#include "ashv2.h"


/**
 * read_input - Reads input from user
 *
 * Return: The input string
 */
char *read_input(void)
{
	char *input = NULL;
	size_t bufsize = 0;

	if (getline(&input, &bufsize, stdin) == -1)
	{
		if (errno == 0)
		{
			/* End of file condition */
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("read_input");
			free(input);
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}
