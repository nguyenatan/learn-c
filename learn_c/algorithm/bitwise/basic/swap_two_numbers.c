#include <stdio.h>
    
void swap(unsigned int *x, unsigned int *y)
{
	if (*x != *y) {
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}

int main(void) 
{
	int x = 4, y = 7;
	
	swap(&x, &y);
	printf("%d %d\n", x, y);
	
	return 0;
}
