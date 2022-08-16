#include <unistd.h>
#include <stdio.h>

int main(void)
{
	
	if (fork() == 0)
		 printf("this is child!\n"); // exit
	else
		printf("this is parent\n"); // wait

	return(0);
}