# Simple Shell Project

## Description

The Simple Shell Project is a Unix command line interpreter developed as part of the ALX Software Engineering program. This shell, named "hsh," provides basic shell functionality, including executing commands, handling arguments, managing the environment, and implementing built-in commands like "exit" and "env."

The goal of this project is to develop a simple yet functional shell that meets the project's requirements while adhering to the provided guidelines and standards.

## Features

- Interactive shell prompt that waits for user input.
- Execution of external commands with or without arguments.
- Handling of the PATH environment variable to locate executables.
- Built-in commands: `exit` to exit the shell and `env` to display the current environment.
- Error handling for command not found and other potential issues.
- Support for interactive and non-interactive modes of operation.
- Compliance with project-specific style and formatting requirements.

## Getting Started

To get started with the Simple Shell, follow these steps:

1. Clone the project repository to your local machine:

   ```bash
   git clone https://github.com/Leedasamurai/simple_shell.git
2. Compile the shell using the provided compilation command:

   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

3. Run the shell:

   ./hsh

./hsh
Usage
Once the shell is running, you can use it as follows:

Enter commands, and the shell will execute them.
Type exit to exit the shell.
Type env to display the current environment.

example:

$ ./hsh
($) /bin/ls
file1.txt  file2.txt  folder/
($) ls -l
total 12
-rw-r--r-- 1 user user   12 Sep  6 10:00 file1.txt
-rw-r--r-- 1 user user   18 Sep  6 10:01 file2.txt
drwxr-xr-x 2 user user 4096 Sep  6 10:02 folder/
($) exit
$

Authors

-Lesego Phuku
