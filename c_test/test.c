#include<stdio.h>
#include <stdlib.h>
int comp(const void *num1, const void *num2)
{
    if (*(int*)num1 == *(int*)num2) {
        return *((int*)num1 + 1) - *((int*)num2 + 1);
    } 
    return *(int*)num1 - *(int*)num2;
}
int main()
{
    int num[6][2] = {{2,4},{4,1},{4,7},{4,2},{9,2},{9,1}};
    qsort(num, 6, 8, comp);
    for (size_t i = 0; i < 6; i++)
    {
        printf("%d %d\n", num[i][0], num[i][1]);
    }
    
    getchar();
    return 0;
}