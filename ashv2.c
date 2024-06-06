#include "ashv2.h"

/**
 * main - The shell program
 *
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure
 */
int main(void)
{
	char *input;
	char **args;
	int status;

	do {
		display_prompt();
		input = read_input();
		args = parse_input(input);
		status = execute_command(args);

		free(input);
		free(args);
	} while (status);
		return (EXIT_SUCCESS);
}
