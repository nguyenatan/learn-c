#include <stdio.h>

unsigned multiply_ten(unsigned value)
{
	return (value << 1) + (value << 3);
}

int main(void)
{
	printf("%d\n", multiply_ten(199) + 8);
	
	return 0;
}
