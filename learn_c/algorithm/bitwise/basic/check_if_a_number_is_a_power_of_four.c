#include <stdio.h>

#define bool int

bool is_power_of_four(unsigned value)
{
	unsigned count = 0;
	
	if ( value && !(value & (value - 1)) ) {
		
		while (value > 1) {
			value >>= 1;
			++count;
		}
	}
	
	return !(count & 1) ? 1 : 0;
}

int main(void)
{
	printf("%d\n", is_power_of_four(1)); // true
	
	return 0;
}
