#include <stdio.h>
#include <stdarg.h>
#define MAXLEN 10
int mon_log(char* format, ...)
{
    char str_tmp[MAXLEN];
    int i=0,j=0;
    va_list vArgList;                           
    va_start (vArgList, format);                 
    i=vsnprintf(str_tmp, MAXLEN, format, vArgList);  
    va_end(vArgList);                            

    printf("%s", str_tmp);  //黄色高亮部分代码

    for(j=0;j<MAXLEN;j++)
    {
        printf("%d  ", str_tmp[j]);
    }
    printf("\n");
    return i;
}

int main()
{   
    int i=mon_log("%s,%d,%d,%c","abc",2,3,'\n');  //绿色高亮部分代码  
    printf("%d\n",i);
    getchar();
    return 0;
}
