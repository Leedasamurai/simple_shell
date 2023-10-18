#include "shell.h"

/**
 * process_user_input - input commands
 *
 * @input: arg typ char pointer
 * @program_name: arg typ char poiter
 */
void process_user_input(char *input, char *program_name)
{
	if (strcmp(input, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (strncmp(input, "exit ", 5) == 0)
	{
		handle_exit_command(input, program_name);
	}
	else if (strcmp(input, "cd") == 0)
	{
		change_to_home_directory();
	}
	else if (strncmp(input, "cd ", 3) == 0)
	{
		change_directory(input);
	}
	else
	{
		execute_command(input, program_name);
	}
}

/**
 * handle_exit_command - handles the exit command
 *
 * @input: arg typ char pointer
 * @program_name: arg typ char point
 */
void handle_exit_command(char *input, char *program_name)
{
	int exit_status = atoi(input + 5);

	if (exit_status < 0)
	{
		fprintf(stderr, "%s: 1: exit: Illegal number: %d\n",
				program_name, exit_status);
		exit(2);
	}

	exit(exit_status);
}

/**
 * change_to_home_directory - changes home directory
 */
void change_to_home_directory(void)
{
	char *home_directory = getenv("HOME");

	if (home_directory != NULL)
	{
		if (chdir(home_directory) == -1)
		{
			perror("chdir");
		}
		setenv("PWD", home_directory, 1);
	}
}
/**
 * change_directory - it uses cd to change dir
 *
 * @input: arg typ char pointer
 */
void change_directory(char *input)
{
	char *directory = input + 3;

	if (strcmp(directory, "-") == 0)
	{
		char *previous_directory = getenv("OLDPWD");

		if (previous_directory != NULL)
		{
			if (chdir(previous_directory) == -1)
			{
				perror("chdir");
			}
			setenv("OLDPWD", getenv("PWD"), 1);
			setenv("PWD", previous_directory, 1);
		}
	}
	else
	{
		if (chdir(directory) == -1)
		{
			perror("chdir");
		}
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", getenv("PWD"), 1);
	}
}

/**
 * main - runs the shell program
 *
 * @argc: arg typ int
 * @argv: arg typ char pointer
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int interactive_mode = isatty(STDIN_FILENO);
	char input[MAX_INPUT_SIZE];
	char *program_name = argv[0];
	size_t len;
	char cwd[256];

	signal(SIGCHLD, handle_signal);

	if (argc > 1)
	{
		fprintf(stderr, "Usage: %s\n", program_name);
		return (EXIT_FAILURE);
	}

	while (1)
	{
		if (interactive_mode)
		{
			if (getcwd(cwd, sizeof(cwd)) != NULL)
			{
				printf("%s $ ", cwd);
				fflush(stdout);
			}
			else
			{
				perror("getcwd");
				return (EXIT_FAILURE);
			}
		}
		if (fgets(input, sizeof(input), stdin) == NULL)
			break;
		len = strlen(input);
		if (len > 0 && input[len - 1] == '\n')
			input[len - 1] = '\0';
		if (strlen(input) == 0)
			continue;
		process_user_input(input, program_name);
	}
	return (EXIT_SUCCESS);
}
