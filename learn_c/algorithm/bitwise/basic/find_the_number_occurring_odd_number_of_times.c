#include <stdio.h>

/*
 * x ^ 0 = x
 * x ^ x = 0
 * x ^ x ^ y = y
 */
int get_odd_occurrence(int *array, unsigned size)
{
	int res = 0;
	
	unsigned i = 0;
	for (; i < size; ++i)
		res ^= array[i];
	
	return res;
		
}

int main(void)
{
	int array[] = {0, 3, 2, 2, 0, 3, 2, 2, 0};
	unsigned size = *(&array+1) - array;
	
	printf("%d\n", get_odd_occurrence(array, size));
	
	return 0;
}
