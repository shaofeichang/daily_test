#include <stdio.h>
#include <strings.h>
#include <string.h>
int main(void)
{
    char a[10] = {'\0'};
    int i = 0;
    int ret = 0;
    memset(a, 1, sizeof(a));
    for (i = 0; i < 10; i++)
    {
        printf("a[%d] = %d  ", i, a[i]);
    }
    ret = snprintf(a, 10, "%d %s", 123, "hello");
    printf("ret = %d\n", ret);

    for (i = 0; i < 10; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }
    getchar();
    return 0;
}

