#include <stdio.h>

#define CHAR_BIT 8

unsigned left_rotate(unsigned value, unsigned count)
{
	const unsigned mask = sizeof(int) * CHAR_BIT - 1;
	count &= mask;
	
	return (value << count) | (value >> (-count & mask));
}

unsigned right_rotate(unsigned value, unsigned count)
{
	const unsigned mask = sizeof(int) * CHAR_BIT - 1;
	count &= mask;
	
	return (value >> count) | (value << (-count & mask));
}

int main(void)
{
	printf("%d\n", left_rotate(2, 4));
	
	printf("%d\n", right_rotate(1024, 5));
	
	return 0;
}
