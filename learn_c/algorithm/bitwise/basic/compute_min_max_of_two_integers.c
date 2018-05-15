#include <stdio.h>

unsigned min(unsigned x, unsigned y)
{
	return y ^ ((x ^ y) & -(x < y));
}

unsigned max(unsigned x, unsigned y)
{
	return x ^ ((x ^ y) & -(x < y));
}

int main(void)
{
	printf("%d\n", min(4, 7));
	printf("%d\n", max(4, 7));
	
	return 0;
}
