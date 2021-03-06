#include <stdio.h>
#include <stdarg.h>
#include<string.h>

#define MAXLEN 10

int mon_log(const char *format, ...)
{
    char str_tmp[MAXLEN];
    int i = 0, j = 0;
    va_list vArgList;
    va_start(vArgList, format);
    i = vsnprintf(str_tmp, MAXLEN, format, vArgList);
    va_end(vArgList);
    printf("%s", str_tmp); 
    // for (j = 0; j < MAXLEN; j++)
    // {
    //     printf("%d  ", str_tmp[j]);
    // }
    printf("\n");
    return i;
}
int mon_log2(char *str_tmp, const char *format, ...)
{
    //char str_tmp[MAXLEN];
    int i = 0, j = 0;
    va_list vArgList;
    va_start(vArgList, format);
    i = vsnprintf(str_tmp, MAXLEN, format, vArgList);
    va_end(vArgList);
    printf("%s", str_tmp); 
    // for (j = 0; j < MAXLEN; j++)
    // {
    //     printf("%d  ", str_tmp[j]);
    // } 
    printf("\n");
    return i;
}

int main()
{
    int i = mon_log("%s,%d,%d,%c", "abcdefghijklmn", 2, 3, '\n'); 
    char str[MAXLEN] = {0};
    
    int j = mon_log2(str, "%s,%d,%d,%c", "abcasdfasdfasdf", 2, 3, '\n'); 
    printf("\n %d   %d\n", i, j);
    printf("sizeof(str) = %d\nstrlen(str) = %d\n",sizeof(str), strlen(str));
    getchar(); 
    return 0;
}
