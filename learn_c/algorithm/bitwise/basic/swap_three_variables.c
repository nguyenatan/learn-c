#include <stdio.h>

void swap_three(unsigned *a, unsigned *b, unsigned *c)
{
	*a ^= *b ^ *c;
	*b ^= *a ^ *c;
	*c ^= *a ^ *b;
	*a ^= *b ^ *c;
}

int main(void)
{
	int a = 2, b = 3, c = 1;
	
	swap_three(&a, &b, &c);
	
	printf("%d %d %d\n", a, b, c); // 1 2 3
	
	return 0;
}
