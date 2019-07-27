#include <stdio.h>
#include <string.h>
// Compare two blocks of memory
int main()
{
    char buffer1[] = "DWgaOtP12df0";
    char buffer2[] = "DWGAOTP12DF0";
    int n;
    n = memcmp(buffer1, buffer2, sizeof(buffer1));
    if (n > 0)
        printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
    else if (n < 0)
        printf("'%s' is less than '%s'.\n", buffer1, buffer2);
    else
        printf("'%s' is the same as '%s'.\n", buffer1, buffer2);

    char *str1 = "hello world";
    char *str2 = "hello world";
    int m = memcmp(str1, str2, strlen(str1));

    if (m > 0)
        printf("'%s' is greater than '%s'.\n", str1, str2);
    else if (m < 0)
        printf("'%s' is less than '%s'.\n", str1, str2);
    else
        printf("'%s' is the same as '%s'.\n", str1, str2);

    getchar();
    return 0;
}