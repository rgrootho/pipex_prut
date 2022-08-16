#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	int i;

	i = 0;

	while(envp[i])
	{
		printf("dit is envp%d: %s\n",i , envp[i]);
		i++;
	}
	return(0);
}