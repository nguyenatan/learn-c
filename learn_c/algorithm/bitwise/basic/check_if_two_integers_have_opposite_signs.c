#include <stdio.h>

#define CHAR_BIT 8
#define bool int

bool is_opposite_sign(unsigned int x, unsigned int y)
{	
	return (x ^ y) >> (sizeof(int) * CHAR_BIT - 1);
}


int main(void)
{
	printf("%d\n", is_opposite_sign(-4, 7));
	
	return 0;
}
