#include <stdio.h>

#define bool int

bool is_power_of_two(unsigned value)
{
	return value && !(value & (value - 1));
}

int main(void)
{
	printf("%d\n", is_power_of_two(0)); // false
	
	return 0;
}
