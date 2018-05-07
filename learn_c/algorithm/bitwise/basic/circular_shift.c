#include <stdio.h>

#define CHAR_BIT 8

unsigned int left_rotate(unsigned int v, unsigned int d)
{
	unsigned int const INT_BIT = sizeof(int) * CHAR_BIT;
	
	return (v << d) | (v >> (INT_BIT - d));
}

unsigned int right_rotate(unsigned int v, unsigned int d)
{
	unsigned int const INT_BIT = sizeof(int) * CHAR_BIT;
	
	return (v >> d) | (v << (INT_BIT - d));
}

int main(void)
{
	printf("%d\n", left_rotate(2, 4));
	
	printf("%d\n", right_rotate(1024, 5));
	
	return 0;
}
