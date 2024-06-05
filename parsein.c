#include "ashv2.h"

/**
 * parse_input - Parses input string into tokens
 * @input: input string to parse
 *
 * Return: An array of tokens
 */
char **parse_input(char *input)
{
	int bufsize = INPUT_SIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, TOKEN_DELIMITERS);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += INPUT_SIZE;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens)
			{
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, TOKEN_DELIMITERS);
	}
	tokens[position] = NULL;
	return (tokens);
}
