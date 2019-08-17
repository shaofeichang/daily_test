#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *src = "Take the test.";
    //  src[0] = 'M' ; // 这会是未定义行为
    char dst[strlen(src) + 1]; // +1 以适应空终止符
    strcpy(dst, src);
    dst[0] = 'M'; // OK
    printf("src = %s\ndst = %s\n", src, dst);

    int r = strcpy_s(dst, sizeof dst, src);
    printf("dst = \"%s\", r = %d\n", dst, r);
    r = strcpy_s(dst, sizeof dst, "Take even more tests.");
    //r!= 0, 返回错误码， dst首位填充0，其他位不变
    printf("dst = \"%s\", r = %d\n", dst, r);
    getchar();
    return 0;
}