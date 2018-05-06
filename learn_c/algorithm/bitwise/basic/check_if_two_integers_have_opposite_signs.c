#include <stdio.h>

#define bool int

bool is_opposite_sign(size_t x, size_t y)
{	
	return (x ^ y) >> 31;
}


int main(void)
{
	printf("%d\n", is_opposite_sign(-4, 7));
	
	return 0;
}
