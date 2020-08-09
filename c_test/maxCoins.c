#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int maxCoins(int* nums, int numsSize) {
    int rec[numsSize + 2][numsSize + 2];
    memset(rec, 0, sizeof(rec));
    int val[numsSize + 2];
    val[0] = val[numsSize + 1] = 1;
    for (int i = 1; i <= numsSize; i++) {
        val[i] = nums[i - 1];
    }
    for (int i = numsSize - 1; i >= 0; i--) {
        for (int j = i + 2; j <= numsSize + 1; j++) {
            for (int k = i + 1; k < j; k++) {
                int sum = val[i] * val[k] * val[j];
                sum += rec[i][k] + rec[k][j];
                rec[i][j] = fmax(rec[i][j], sum);
            }
        }
    }
    return rec[0][numsSize + 1];
}
int main()
{
    int nums[] = {3,1,5,8};
    int ret = maxCoins(nums, sizeof(nums)/sizeof(nums[0]));
    printf("ret = %d\n", ret);
    getchar();
    return 0;
}