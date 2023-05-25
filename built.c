#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
int main(void)/* int void */
{
char buffer[BUFFER_SIZE];
char *command;
int status;
while (1)
{
printf("$ "); /* Display the prompt */
fflush(stdout);
if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
{
printf("\n");
break; /* Handle end of file (Ctrl+D) */
}
/* Remove the trailing newline character */
buffer[strcspn(buffer, "\n")] = '\0';
/* Execute the command */
command = strtok(buffer, " ");
if (command != NULL)
{
pid_t pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/* Child process */
execlp(command, command, NULL);
/* If exec returns, it means the command is not found */
perror("exec");
exit(EXIT_FAILURE);
}
else
{
/* Parent process */
waitpid(pid, &status, 0);
}
}
}
return (EXIT_SUCCESS);
}

