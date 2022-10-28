#include <stdio.h>
#include <stdlib.h>

void test_function(void)
{
	exit(1);
	return;
}

int main(void)
{
	printf("testje\n");
	test_function();
	printf("niet gelukt :(\n");

	return(0);
}