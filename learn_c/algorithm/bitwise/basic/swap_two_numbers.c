#include <stdio.h>
    
void swap(unsigned *x, unsigned *y)
{
	if (x == y)
		return;
	
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

int main(void) 
{
	int x = 4, y = 7;
	
	swap(&x, &y);
	printf("%d %d\n", x, y);
	
	return 0;
}
