#include <stdio.h>

static const unsigned char bits_set_table_256[256] =
{
	#define B2(n) 	n,	n+1,	n+1,	n+2
	#define B4(n)	B2(n),	B2(n+1),B2(n+1),B2(n+2)
	#define B6(n)	B4(n),	B4(n+1),B4(n+1),B4(n+2)
	B6(0), B6(1), B6(1), B6(2)
};

unsigned count_set_bit(unsigned value)
{
	return bits_set_table_256[value & 0xFF] +
	       bits_set_table_256[(value >> 8) & 0xFF] +
	       bits_set_table_256[(value >> 16) & 0xFF] +
	       bits_set_table_256[(value >> 24) & 0xFF];
}

/*
 * flipped_count - Count number of bits to be flipped to convert A to B
 */
unsigned flipped_count(unsigned x, unsigned y)
{
	return count_set_bit(x ^ y);
}

int main(void)
{
	printf("%d\n", count_set_bit(47)); // 5
	
	printf("%d\n", flipped_count(4, 7)); // 2
	
	return 0;
}
