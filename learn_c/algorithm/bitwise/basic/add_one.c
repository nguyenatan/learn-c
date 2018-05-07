#include <stdio.h>
    
unsigned add_one(unsigned v)
{
	return -(~v);
}

int main(void) 
{
	printf("%d\n", add_one(419));
	
	return 0;
}
