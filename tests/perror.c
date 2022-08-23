#include <stdio.h>
#include <string.h>
#include <sys/errno.h>

int main(void)
{
	char string[] = "pipo";

	//perror(string);
	strerror(errno);
	return(0);
}