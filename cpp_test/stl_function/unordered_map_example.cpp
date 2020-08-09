// unordered_map::insert
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> indices;
        int xMin = INT_MAX, xMax = INT_MIN;
        for (int i = 0; i < n; ++i) {
            for (const int& x: nums[i]) {
                indices[x].push_back(i);
                xMin = min(xMin, x);
                xMax = max(xMax, x);
            }
        }

        vector<int> freq(n);
        int inside = 0;
        int left = xMin, right = xMin - 1;
        int bestLeft = xMin, bestRight = xMax;

        while (right < xMax) {
            ++right;
            if (indices.count(right)) {
                for (const int& x: indices[right]) {
                    ++freq[x];
                    if (freq[x] == 1) {
                        ++inside;
                    }
                }
                while (inside == n) {
                    if (right - left < bestRight - bestLeft) {
                        bestLeft = left;
                        bestRight = right;
                    }
                    if (indices.count(left)) {
                        for (const int& x: indices[left]) {
                            --freq[x];
                            if (freq[x] == 0) {
                                --inside;
                            }
                        }
                    }
                    ++left;
                }
            }
        }
        return {bestLeft, bestRight};
    }
};
int main()
{
    vector<vector<int>> inputNum = {{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
    Solution so;
    so.smallestRange(inputNum);
    std::unordered_map<std::string, double>
        myrecipe,
        mypantry = {{"milk", 2.0}, {"flour", 1.5}};

    std::pair<std::string, double> myshopping("baking powder", 0.3);

    myrecipe.insert(myshopping);                                       // copy insertion
    myrecipe.insert(std::make_pair<std::string, double>("eggs", 6.0)); // move insertion
    myrecipe.insert(mypantry.begin(), mypantry.end());                 // range insertion
    myrecipe.insert({{"sugar", 0.8}, {"salt", 0.1}});                  // initializer list insertion

    std::cout << "myrecipe contains:" << std::endl;
    for (auto &x : myrecipe)
        std::cout << x.first << ": " << x.second << std::endl;

    std::cout << std::endl;
    return 0;
}