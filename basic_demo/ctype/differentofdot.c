#include <stdio.h>
#define f(a, b) a##b
#define g(a)  #a
#define h(a) g(a)
#define STR(s) #s
#define CONS(a, b) int(a##e##b)

int main()
{
    printf((f(1, 2)));
    printf(g(f(1, 2)));
    printf(STR(vck));           // 输出字符串"vck"
    printf("%d\n", CONS(2, 3)); // 2e3 输出:2000

    return 0;
}
