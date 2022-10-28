#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include <unistd.h>

int main(void)
{
	char string[] = "pipo";

	access("pipo.txt", F_OK);
	perror(string);
	strerror(errno);
	return(0);
}