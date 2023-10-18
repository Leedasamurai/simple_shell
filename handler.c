#include "shell.h"

/**
 * handle_signal - handle termination of child processs
 *
 * @signo: arg type int
 */
void handle_signal(int signo)
{
	if (signo == SIGCHLD)
	{
		int status;
		pid_t pid;

		while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
		{
			printf("[%d] exited with status %d\n", pid, WEXITSTATUS(status));
		}
	}
}
