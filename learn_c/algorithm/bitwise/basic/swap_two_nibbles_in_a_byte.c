#include <stdio.h>

unsigned char swap_nibble(unsigned char value)
{
	return (value & 0x0F) << 4 | (value & 0xF0) >> 4;
}

int main(void)
{
	printf("%d\n", swap_nibble(242)); // 47	
	
	return 0;
}
