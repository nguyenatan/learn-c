#include <stdio.h>

// Find count of positive integers i such that 0 <= i <= value
// and (value + i) = (value ^ i).
// Formula:
//	a + b = a ^ b + 2 * (a & b)

unsigned count(unsigned value)
{
	unsigned count = 0;
	
	while (value) {
		
		if (!(value & 1))
			++count;
		
		value >>= 1;
	}
	
	return 1u << count;
}

int main(void)
{
	printf("%d\n", count(420)); // 32
	
	return 0;
}
