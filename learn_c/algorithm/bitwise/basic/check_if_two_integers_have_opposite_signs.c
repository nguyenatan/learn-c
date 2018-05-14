#include <stdio.h>

#define bool int
#define CHAR_BIT 8

bool is_opposite_sign(unsigned x, unsigned y)
{	
	return (x ^ y) >> (sizeof(int) * CHAR_BIT - 1);
}


int main(void)
{
	printf("%d\n", is_opposite_sign(-4, 7)); // true
	
	return 0;
}
