#include <stdio.h>
#include <stdarg.h>
int debug_log(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    // int n = printf(fmt, ap);
    int n = vfprintf(stdout, fmt, ap);
    int m = vprintf(fmt, ap);
    va_end(ap);

    return n;
}
void myPrint(int num, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    while (num--)
    {
        printf(format, va_arg(args, int));
    }
    va_end(args);
}
double average(int num, ...)
{
    va_list valist;
    double sum = 0.0;
    int i;
    /* 为 num 个参数初始化 valist */
    va_start(valist, num);
    /* 访问所有赋给 valist 的参数 */
    for (i = 0; i < num; i++)
    {
        sum += va_arg(valist, int);
    }
    /* 清理为 valist 保留的内存 */
    va_end(valist);
    return sum / num;
}

int main()
{
    int n = debug_log("%d%d%d %d %d\n", 1, 2, 3, 4, 5);
    printf("debug_log n = %d\n", n);
    printf("\n");
    myPrint(5, "%d\t", 1, 2, 3, 4, 5);
    printf("\n");
    printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2, 3, 4, 5));
    printf("Average of 5, 10, 15 = %f\n", average(3, 5, 10, 15));
    getchar();
    return 0;
}