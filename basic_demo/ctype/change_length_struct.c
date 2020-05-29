#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    int id;
    char name[0];
} stu_t;
int main()
{
    stu_t *s = NULL;              //定义一个结构体指针
    s = (stu_t *)malloc(sizeof(*s) + 100); //sizeof(*s)获取的是4，但加上了100，4字节给id成员使用，100字节是属于name成员的
    s->id = 1010;
    strcpy(s->name, "hello");
    printf("%d\n", sizeof(s));
    printf("%d\n", sizeof(*s));
    getchar();
    return 0;
}
