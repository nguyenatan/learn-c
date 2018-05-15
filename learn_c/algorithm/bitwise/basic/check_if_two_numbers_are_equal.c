#include <stdio.h>

#define bool int

unsigned are_equal(unsigned x, unsigned y)
{
	return !(x ^ y);
}

int main(void)
{
	printf("%d\n", are_equal(4, 7)); // false
	
	return 0;
}
