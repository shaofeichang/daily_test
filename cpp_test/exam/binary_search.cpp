#include <bits/stdc++.h>
using namespace std;
int right_bound1(vector<int> nums, int target)
{
    if (nums.size() == 0)
        return -1;
    int left = 0, right = nums.size();
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            left = mid + 1; // 注意
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid;
        }
    }
    if (left == 0)
        return -1;
    return nums[left - 1] == target ? (left - 1) : -1;
}
int right_bound2(vector<int> nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] == target)
        { // 这⾥改成收缩左侧边界即可
            left = mid + 1;
        }
    } // 这改为检查right越界的情况
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}
int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    cout << right_bound1(nums, 1) << endl;
    cout << right_bound2(nums, 1) << endl;
    system("pause");
    return 0;
}