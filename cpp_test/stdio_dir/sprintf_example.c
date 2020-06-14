#include <stdio.h>
#include <string.h>
// Write formatted data to string
int main()
{
    char buffer[50];
    int n, a = 5, b = 3;
    n = sprintf(buffer, "%d plus %d is %d", a, b, a + b);
    printf("[%s] is a string %d chars long\n", buffer, n);
    printf("sizeof(buffer) = %d, strlen(buffer) = %d \n", sizeof(buffer), strlen(buffer));
    getchar();
    return 0;
}