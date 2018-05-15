#include <stdio.h>

unsigned subtract_one(unsigned value)
{
	return ~-value;
}

int main(void)
{
	printf("%d\n", subtract_one(-419));
	
	return 0;
}
