#include <stdio.h>

unsigned count_xor(unsigned value)
{
	unsigned count_0 = 0, count_1 = 0;
	
	while (value) {
		!(value & 1) ? ++count_0 : ++count_1;
		value >>= 1;
	}
	
	return count_0 ^ count_1;
}

int main(void)
{
	printf("%d\n", count_xor(10)); // 0
	
	return 0;
}
