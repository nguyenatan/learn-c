#include <stdio.h>

#define bool int

bool is_odd(unsigned value)
{
	return value & 1;
}

int main(void) 
{
	printf("%d\n", is_odd(47));
	
	return 0;
}
