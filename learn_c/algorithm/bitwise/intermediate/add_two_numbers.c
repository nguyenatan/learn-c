#include <stdio.h>

unsigned add(unsigned x, unsigned y)
{
	while (y) {
		unsigned carry = x & y;
		
		x ^= y;
		
		y = carry << 1;
	}
	
	return x;
}

int main(void)
{
	printf("%d\n", add(4, 7)); // 11
	
	return 0;
}
