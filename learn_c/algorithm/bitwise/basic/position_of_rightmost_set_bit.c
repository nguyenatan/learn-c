#include <stdio.h>
#include <math.h>

unsigned get_rightmost_pos(unsigned value)
{
	return log2(value & -value) + 1;
}

int main(void)
{
	printf("%d\n", get_rightmost_pos(6)); // 2
	
	return 0;
}
