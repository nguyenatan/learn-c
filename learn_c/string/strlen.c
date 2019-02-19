#include <stdio.h>

size_t strlen(const char *s)
{
    size_t i;
    for (i = 0; s[i]; ++i) ;
    return i;
}

int main(void)
{
    char *str = "Nguyen A Tan";
    
    printf("%d\n", strlen(str)); // 12

    return 0;
}
