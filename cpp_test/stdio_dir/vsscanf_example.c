#include <stdio.h>
#include <stdarg.h>
// Read formatted data from string into variable argument list
void GetMatches(const char *str, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vsscanf(str, format, args);
    va_end(args);
}

int main()
{
    int val;
    char buf[100];

    GetMatches("99 bottles of beer on the wall", " %d %s %s ", &val, buf, buf + 10);

    printf("Product: %s\nQuantity: %d\n Third: %s\n", buf, val, buf + 10);
    getchar();
    return 0;
}