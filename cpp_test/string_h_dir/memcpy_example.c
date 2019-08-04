#include <string.h>
#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
// Copy block of memory
struct
{
    char name[40];
    int age;
} person, person_copy;

int main()
{
    char myname[] = "Pierre de Fermat";
    /* using memcpy to copy string: */
    memcpy(person.name, myname, strlen(myname) + 1);
    person.age = 46;

    /* using memcpy to copy structure: */
    memcpy(&person_copy, &person, sizeof(person));
    printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);

    char str1[] = "helloworld";
    memcpy(str1 + 1, str1 + 3, 5);
    puts(str1);

    char str2[] = "memmove can be very useful......";
    memmove(str2 + 20, str2 + 15, 11);
    puts(str2);

    {
        char str[] = "1234567890";
        puts(str);
        memmove(str + 4, str + 3, 3); // 从 [4,5,6] 复制到 [5,6,7]
        puts(str);

        // 设置分配的内存的有效类型为 int
        int *p = (int *)malloc(3 * sizeof(int)); // 分配的内存无有效类型
        int arr[3] = {1, 2, 3};
        memmove(p, arr, 3 * sizeof(int)); // 分配的内存现在拥有有效类型

        // 转译数据
        double d = 0.1;
        //    int64_t n = *(int64_t*)(&d); // 严格别名使用违规
        int64_t n;
        memmove(&n, &d, sizeof d); // OK
        printf("%a is %ld \" PRIx64 \" as an int64_t\n", d, n);

        char src[] = "aaaaaaaaaa";
        char dst[] = "xyxyxyxyxy";
        int r = memmove_s(dst, sizeof dst, src, 5);
        printf("dst = \"%s\", r = %d\n", dst, r);
        r = memmove_s(dst, 5, src, 10); //  count 大于 destsz
        printf("dst = \"");
      
        for (size_t ndx = 0; ndx < sizeof dst; ++ndx)
        {
            char c = dst[ndx];
            c ? printf("%c", c) : printf("\\0");
        }
        printf("\", r = %d\n", r);
    }
    getchar();
    return 0;
}