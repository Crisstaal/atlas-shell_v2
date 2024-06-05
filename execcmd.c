#include "ashv2.h"
#include <sys/stat.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

/**
 * search_path - Searches for the command in the directories listed in PATH
 * @command: The command to search for
 *
 * Return: Full path to the command if found, NULL otherwise
 */
char *search_path(char *command)
{
	char *path, *dir;
	char *full_path = malloc(PATH_MAX);
	struct stat st;

	if (full_path == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	path = getenv("PATH");
	if (!path)
	{
		free(full_path);
		return (NULL);
	}

	dir = strtok(path, ":");
	while (dir != NULL)
	{
		sprintf(full_path, "%s/%s", dir, command);
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			return full_path;
		}
		dir = strtok(NULL, ":");
	}

	free(full_path);
	return (NULL);
}

/**
 * execute_command - Executes a command
 * @args: The arguments for the command
 *
 * Return: 1 if the shell should continue running, 0 if it should terminate
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;
	char *path;
	extern char **environ;

	if (args[0] == NULL)
		return (1);
	if (_strcmp(args[0], "cd") == 0)
		return (shell_cd(args));
	if (_strcmp(args[0], "exit") == 0)
		return (shell_exit(args));
	if (_strcmp(args[0], "env") == 0)
		return (shell_env(args));
	pid = fork();
	if (pid == 0)
	{
		if (args[0][0] == '/' || args[0][0] == '.')
			path = args[0];
		else
			path = search_path(args[0]);
		if (path == NULL)
		{
			fprintf(stderr, "hsh: %s: command not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
		if (execve(path, args, environ) == -1)
			perror("hsh");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("hsh");
	else
	{
		do
			waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
