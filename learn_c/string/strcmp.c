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
    char key[] = "apple";
    char buffer[80];

    do {
        printf("Guess my favorite fruit? ");
        fflush(stdout);
        scanf("%79s", buffer);
    } while (strcmp(key, buffer) != 0);

    puts("Correct answer!");

    return 0;
}
