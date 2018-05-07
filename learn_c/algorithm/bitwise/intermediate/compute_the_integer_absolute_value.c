#include <stdio.h>

#define CHAR_BIT 8

int abs(unsigned value)
{
	const int mask = value >> (sizeof(int) * CHAR_BIT - 1);
	
	return (value + mask) ^ mask;
}

int main(void)
{
	printf("%d\n", abs(-47));
	
	return 0;
}
