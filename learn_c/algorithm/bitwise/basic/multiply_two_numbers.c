#include <stdio.h>

unsigned russian_peasant(unsigned _double, unsigned _halve)
{
	int res = 0;
	
	while (_halve > 0) {
		
		if (_halve & 1)
			res += _double;
		
		_double <<= 1;
		_halve >>= 1;
	}
	
	return res;
}

int main(void)
{
	printf("%d\n", russian_peasant(4, 7)); // 28
	
	return 0;
}
