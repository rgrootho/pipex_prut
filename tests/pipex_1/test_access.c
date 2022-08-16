#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int test;

	test = 5;
	test = access("test_2.c", F_OK);
	printf("%d\n", test);
	return(0);
}