#include <stdio.h>

unsigned get_modulo(unsigned value, unsigned power_of_two)
{
	return value & (power_of_two - 1);
}

int main(void)
{
	printf("%d\n", get_modulo(15, 8)); // 7
	
	return 0;
}
