#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec1;
    int n;
    cin >> n;
    int stuTotal = n;
    while (n--)
    {
        int ai;
        cin >> ai;
        vec1.push_back(ai);
    }
    int nums;
    cin >> nums;
    vector<int> vec2;
    while (nums--)
    {
        int ai;
        cin >> ai;
        vec2.push_back(ai);
    }

    for (size_t i = 0; i < vec2.size(); i++)
    {
        int renshu = 0;
        for (int j = 0; j < vec1.size(); j++)
        {
            if (vec1.at(j) <= vec1.at(vec2.at(i)-1))
            {
                renshu++;
            }
        }
        if (i != vec1.size() - 1)
            printf("%8f\n", (double)(renshu - 1) / stuTotal * 100);
        else
            printf("%8f\n", (double)(renshu - 1) / stuTotal * 100);
    }
    system("pause");
    return 0;
}