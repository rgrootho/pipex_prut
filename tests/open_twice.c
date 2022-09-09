#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int open_1;
	int open_2;
	int write_1;
	int write_2;

	open_1 = open("infile.txt", O_RDONLY);
	open_2 = open("infile.txt", O_WRONLY);
	write_1 = write(open_1, "uwu", 3);
	write_2 = write(open_2, "uwu", 3);

	printf("%d\n%d\n%d\n%d\n", open_1, open_2, write_1, write_2);
	close(open_1);
	close(open_2);
	return(0);
}