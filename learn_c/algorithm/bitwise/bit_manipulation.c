#include <stdio.h>

/*
 * Bit indexing begins at 0.
 * 1u in binary ...0001
 * (1u << 2) is ...0100
 */
unsigned set_a_bit(unsigned value, unsigned index)
{
	return value | (1u << index);
}

unsigned clear_a_bit(unsigned value, unsigned index)
{
	return value & ~(1u << index);
}

unsigned toggle_a_bit(unsigned value, unsigned index)
{
	return value ^ (1u << index);
}

unsigned test_a_bit(unsigned value, unsigned index)
{
	return value & (1u << index);
}

int main(void)
{
	printf("%d\n", set_a_bit(0, 0)); // 1
	
	printf("%d\n", clear_a_bit(2, 1)); // 0
	
	printf("%d\n", toggle_a_bit(~1, 0)); // -1
	
	if (test_a_bit(4, 2))
		printf("yes\n");
	else
		printf("no\n");
	
	return 0;
}
