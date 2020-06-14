#include <stdio.h>
#include <stdarg.h>
// Print formatted data from variable argument list to stdout
void WriteFormatted(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

int main()
{
    WriteFormatted("Call with %d variable argument.\n", 1);
    WriteFormatted("Call with %d variable %s.\n", 2, "arguments");
    getchar();
    return 0;
}