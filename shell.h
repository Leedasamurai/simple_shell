#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 64

int main(int argc, char *argv[]);
void process_user_input(char *input, char *program_name);
void handle_exit_command(char *input, char *program_name);
void change_to_home_directory(void);
void change_directory(char *input);
void execute_command(char *input, char *program_name);
void tokenize_input(char *input, char *tokens[], int *token_count);
void handle_builtin_exit(char *input, char *program_name);
void execute_external_command(char *tokens[], char *program_name);
void handle_signal(int signo);

#endif /* SHELL_H */
