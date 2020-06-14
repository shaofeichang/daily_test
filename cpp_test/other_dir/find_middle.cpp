#include <iostream>
#include <vector>
using namespace std;
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    const int n1 = nums1.size();
    const int n2 = nums2.size();
    if (n1 > n2)
        return findMedianSortedArrays(nums2, nums1);
    const int k = (n1 + n2 + 1) / 2;
    int left = 0;
    int right = n1;
    while (left < right)
    {
        const int m1 = left + (right - left) / 2;
        const int m2 = k - m1;
        if (nums1[m1] < nums2[m2 - 1])
            left = m1 + 1;
        else
            right = m1;
    }
    const int m1 = left;
    const int m2 = k - left;
    const int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1],
                       m2 <= 0 ? INT_MIN : nums2[m2 - 1]);
    if ((n1 + n2) % 2 == 1)
        return c1;
    const int c2 = min(m1 >= n1 ? INT_MAX : nums1[m1],
                       m2 >= n2 ? INT_MAX : nums2[m2]);
    return (c1 + c2) * 0.5;
}
int main()
{
    vector<int> vec1 = {1,2,3,4}; // 1 2 3 3 4 4 5 5 6 7 9 
    vector<int> vec2 = {7,8,9,10,11};
    cout<<findMedianSortedArrays(vec1, vec2)<<endl;;
    system("pause");
    return 0;
}