#include <stdio.h>

unsigned count_set_bit(unsigned value)
{
	unsigned count = 0;
	
	while (value) {
		value &= (value - 1);
		++count;
	}
	
	return count;
}

int main(void)
{
	printf("%d\n", count_set_bit(47)); // 5
	
	return 0;
}
