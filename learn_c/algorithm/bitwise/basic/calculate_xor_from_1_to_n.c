#include <stdio.h>

unsigned compute_xor(const unsigned n)
{
	switch (n & 3) {
		case 0:
			return n;
		case 1:
			return 1;
		case 2:
			return n + 1;
		case 3:
			return 0;
	}
}

int main(void)
{
	printf("%d\n", compute_xor(47)); // 0
	
	return 0;
}
