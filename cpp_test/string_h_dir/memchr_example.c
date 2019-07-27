#include <stdio.h>
#include <string.h>
// Locate character in block of memory
int main()
{
    char *pch;
    char str[] = "Examplpe string";
    pch = (char *)memchr(str, 'p', strlen(str));
    if (pch != NULL)
        printf("'p' found at position %d.\n", pch - str + 1);
    else
        printf("'p' not found.\n");
    printf("pch is point to: %s\n", pch);
    getchar();
    return 0;
}