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
    printf("\n sizeof(a): %d ,  strlen(a): %d \n ", sizeof(a), strlen(a));
    ret = snprintf(a, NUMLEN, "%u %s", 123, "helloqweopo");//输入长度超过NUMLEN时，返回-1，传递数据成功，char数组，结尾非'\0'
    printf("ret = %d\n", ret);
    printf("sizeof(a): %d ,  strlen(a): %d \n str a : %s", sizeof(a), strlen(a), a);
    for (i = 0; i < NUMLEN; i++)
    {
        printf("a[%d] = %d  ", i, a[i]);
    }
    printf("\t");
    getchar();
    return 0;
}
