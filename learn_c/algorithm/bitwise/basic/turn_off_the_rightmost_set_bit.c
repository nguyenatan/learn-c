#include <stdio.h>

unsigned unset_rightmost(unsigned value)
{
	return value & (value - 1);
}

int main(void)
{
	printf("%d\n", unset_rightmost(4)); // 0
	
	return 0;
}
