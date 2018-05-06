#include <stdio.h>
    
void show_bit(unsigned int x)
{
	int i = sizeof(int) * 8 - 1;
	for(; i >= 0; --i) {
		
		if ( !((i + 1) % 8) )
			putchar(' ');
		
		(x & (1u << i)) ? putchar('1') : putchar('0');
	}
	
    	printf("\n");
}

int main() 
{
	printf("47 in binary");
	show_bit(47);
	
	return 0;
}
