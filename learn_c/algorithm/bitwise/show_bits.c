#include <stdio.h>

#define CHAR_BIT 8
    
void show_bit(unsigned value)
{	
	int i = sizeof(int) * CHAR_BIT - 1;
	for(; i >= 0; --i) {
		
		if (i != 31 && !((i + 1) % 4))
			putchar(' ');
		
		(value & (1u << i)) ? putchar('1') : putchar('0');
	}
	
    	printf("\n");
}

int main(void) 
{
	printf("47 in binary ");
	show_bit(47);
	
	return 0;
}
