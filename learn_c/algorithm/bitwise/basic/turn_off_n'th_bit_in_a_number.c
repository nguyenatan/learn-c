#include <stdio.h>

unsigned int turn_off_nth_bit(unsigned int v, unsigned int n)
{
	return v & ~(1u << (n - 1));
}

int main(void) 
{
	printf("%d\n", turn_off_nth_bit(47, 6));
	
	return 0;
}
