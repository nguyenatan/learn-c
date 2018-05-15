#include <stdio.h>

unsigned my_xor(unsigned x, unsigned y)
{
	return (x | y) & (~x | ~y);
}

int main(void)
{
	printf("%d\n", my_xor(4, 3)); // 7
	
	return 0;
}
