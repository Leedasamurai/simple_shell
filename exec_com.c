#include "shell.h"

/**
 * tokenize_input - tokenizes the string input
 *
 * @input: the input
 * @tokens: the pointer array
 * @token_count: the token counter
 */
void tokenize_input(char *input, char *tokens[], int *token_count)
{
	char *token = strtok(input, " ");
	*token_count = 0;

	while (token != NULL)
	{
		tokens[(*token_count)++] = token;
		token = strtok(NULL, " ");
	}

	tokens[*token_count] = NULL;
}

/**
 * handle_builtin_exit - hnadles exit
 *
 * @input: the input
 * @program_name: the pointer to the name
 */
void handle_builtin_exit(char *input, char *program_name)
{
	if (strncmp(input, "exit ", 5) == 0)
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
}

/**
 * execute_external_command - execute external commands
 *
 * @tokens: pointer array to tokens
 * @program_name: name of progam pointer
 */
void execute_external_command(char *tokens[], char *program_name)
{
	if (execvp(tokens[0], tokens) == -1)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", program_name,
				1, tokens[0]);
		exit(2);
	}
}
/**
 * execute_command - it is used to execute a command
 *
 * @input: arg typ char pointer
 * @program_name: name of program poin
 */
void execute_command(char *input, char *program_name)
{
	int pid;
	int status;
	int background = 0;
	char *tokens[MAX_TOKENS];
	int token_count = 0;

	if (input[strlen(input) - 1] == '&')
	{
		background = 1;
		input[strlen(input) - 1] = '\0';
	}

	handle_builtin_exit(input, program_name);
	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		tokenize_input(input, tokens, &token_count);
		execute_external_command(tokens, program_name);
	}
	else
	{
		if (background)
		{
			printf("[%d] %s\n", pid, input);
		} else
		{
			if (wait(&status) == -1)
			{
				perror("wait");
				exit(EXIT_FAILURE);
			}
		}
	}
}
