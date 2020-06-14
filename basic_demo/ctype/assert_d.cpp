#include <stdio.h>  /* printf */
#include <assert.h> /* assert */
#define NDEBUG
void print_number(int *myInt)
{
    assert(myInt != NULL);
    printf("%d\n", *myInt);
}

int main()
{
    int a = 10;
    int *b = NULL;
    int *c = NULL;
jkljl
    b = &a;

    print_number(b);
    print_number(c);

    getchar();
    return 0;
}