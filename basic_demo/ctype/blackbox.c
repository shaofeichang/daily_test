#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BLACLBOX_MAX 10
typedef struct
{
    int index;
    int isfull;
    int msg[BLACLBOX_MAX];
} Blackbox;
Blackbox bb;

void putBkb(int num)
{
    if(bb.index == 10) {
        bb.index = 0;
        bb.isfull = 1;
    }
    bb.msg[bb.index++] = num;
}
void printBkb()
{
    for (int i = bb.index - 1; i >= 0; i--) {
        printf("index = %d, msg = %d\n", i, bb.msg[i]);
    }
    if (!bb.isfull) {
        return;
    }
    for (int i = BLACLBOX_MAX - 1; i >= bb.index; i--) {
        printf("index = %d, msg = %d\n", i, bb.msg[i]);
    }
}
int main()
{
    for (int i = 1; i < 8; i++) {
        putBkb(i);
    }
    printBkb();
    getchar();
    return 0;
}