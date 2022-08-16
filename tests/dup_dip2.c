#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
	int fd_test;
	int copy_fd;

	fd_test = open("tekst_voor_dup.txt", O_RDWR , O_APPEND );
	printf("hahahah output hihi\n");
	copy_fd = dup(1);
	printf("dit is copy_fd: %d\n", copy_fd);
	write(copy_fd, "hey\n", 4);
	dup2(fd_test, 1);
	printf("gaat deze dan nu in de file?\n");
	write(copy_fd, "hey2\n", 5);


	close(fd_test);
	return(0);

}