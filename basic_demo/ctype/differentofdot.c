#include <stdio.h>
#define f(a, b) a##b
#define g(a)  #a
#define h(a) g(a)
#define STR(s) #s
#define CONS(a, b) int(a##e##b)

int main()
{
    printf("%d\n", (f(1, 2)));
    printf(g(f(123,1234)4645)); 
    printf(h(f(123,1234))); 
    printf("\n");
    printf(STR(vck));           // 输出字符串"vck"
    printf("\n");
    printf("%d\n", CONS(2, 3)); // 2e3 输出:2000
    printf(f(g(a),g(b)));
    getchar();
    return 0;
}
