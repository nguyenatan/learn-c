#include <stdio.h>

#define CHAR_BIT 8

int abs(unsigned int v)
{
	int const mask = v >> (sizeof(int) * CHAR_BIT - 1);
	
	return (v + mask) ^ mask;
}

int main(void)
{
	printf("%d\n", abs(-47));
	
	return 0;
}
