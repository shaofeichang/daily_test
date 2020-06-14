#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    string s1 = "aaa", s2 = "bbb";
    s1 + s2 = "as"; 
    int testCounts;
    int testNums;
    vector<int> vec;
    cin >> testCounts;
    if (testCounts < 0 || testCounts > 10)
        return 0;
    while (testCounts--)
    {

    }
        cin >> testNums;
        int testNumReocrd = testNums;
        while (testNums--)
        {
            int inputNum;
            cin >> inputNum;
            vec.push_back(inputNum);
            getchar();
        }
        int returnNum = 0;
        for (size_t i = 0; i < testNumReocrd - 2; i++)
        {
            if (vec.at(i) + vec.at(i + 2) < vec.at(i))
            {
                returnNum = 0;
            }
        }
        if (returnNum == 0 &&
            (vec.at(vec.size() - 1) + vec.at(0) > vec.at(1)) &&
            (vec.at(vec.size() - 2) + vec.at(0) > vec.at(vec.size() - 1)))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    
    system("pause");
    return 0;
}