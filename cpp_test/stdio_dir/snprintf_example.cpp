#include <stdio.h>
#include <strings.h>
#include <string.h>
#define NUMLEN 15
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
    printf("\n sizeof(a): %d ,  strlen(a): %d \n ", sizeof(a), strlen(a));
    ret = snprintf(a, NUMLEN, "%d %s", 123, "helloqwe");
    printf("ret = %d\n", ret);
    printf("sizeof(a): %d ,  strlen(a): %d \n ", sizeof(a), strlen(a));
    for (i = 0; i < NUMLEN; i++)
    {
        printf("a[%d] = %d  ", i, a[i]);
    }
    printf("\t");
    getchar();
    return 0;
}
