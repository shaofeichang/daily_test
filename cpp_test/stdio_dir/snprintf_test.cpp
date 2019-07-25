#include <stdio.h>
#include <strings.h>
#include <string.h>
#define NUMLEN 20
int main(void)
{
    char a[NUMLEN] = {'\0'};
    int i = 0;
    int ret = 0;
    memset(a, 1, sizeof(a));
    for (i = 0; i < NUMLEN; i++)
    {
        printf("a[%d] = %d ", i, a[i]);
    }
    ret = snprintf(a, NUMLEN, "%d %s", 123, "helloppp");
    printf("ret = %d\n", ret);

    for (i = 0; i < NUMLEN; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }
    getchar();
    return 0;
}

