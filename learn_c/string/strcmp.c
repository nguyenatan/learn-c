#include <stdio.h>

int strcmp(const char *s1, const char *s2)
{
    while (*s1 == *s2++)
        if (*s1++ == '\0')
            return 0;
    
    return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
}

int main(void)
{
    char s1[] = "abc";
    char s2[] = "xyz";

    printf("%d\n", strcmp(s1, s2) != 0); // 1

    return 0;
}
