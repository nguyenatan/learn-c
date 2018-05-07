#include <stdio.h>

unsigned turn_off_nth_bit(unsigned value, unsigned n)
{
	return value & ~(1u << (n - 1));
}

int main(void) 
{
	printf("%d\n", turn_off_nth_bit(47, 6));
	
	return 0;
}
