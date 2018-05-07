#include <stdio.h>
    
unsigned int add_one(unsigned int v)
{
	return -(~v);
}

int main(void) 
{
	printf("%d\n", add_one(419));
	
	return 0;
}
