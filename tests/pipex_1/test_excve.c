#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char path[] = "/bin/ls";

	char *argvec[] = {"ls","-l","-a", NULL};
	char *envvec[] = {NULL};

	printf("star of execve call :%s\n", path);
	printf("=====================================\n");
	if (execve(path, argvec, envvec ) == -1)
		perror("could not execute execve");
	
	printf("something went wrong\n");
	return(0);
}