#include <bits/stdc++.h>
using namespace std;
int romanToInt(string s)
{
    int result = 0;        //存放结果
    map<char, int> luomab; //建立罗马表
    //插入对应关系
    luomab.insert(map<char, int>::value_type('I', 1));
    luomab.insert(map<char, int>::value_type('V', 5));
    luomab.insert(map<char, int>::value_type('X', 10));
    luomab.insert(map<char, int>::value_type('L', 50));
    luomab.insert(map<char, int>::value_type('C', 100));
    luomab.insert(map<char, int>::value_type('D', 500));
    luomab.insert(map<char, int>::value_type('M', 1000));
    for (int i = 0; i < s.length(); i++)
    {
        if (luomab[s[i]] >= luomab[s[i + 1]])
            result += luomab[s[i]];
        else
        {
            result += (luomab[s[i + 1]] - luomab[s[i]]);
            i++;
        }
    }
    return result;
}
int main()
{
    string s = "MCMXCIV";
    cout << romanToInt(s) << endl;
    system("pause");
    return 0;
}
// int main()
// {
//     int N;
//     cin >> N;
//     int ret = 0;
//     for (size_t i = 1; i < N / 3; i++)
//     {
//         for (size_t j = i; j < N / 2; j++)
//         {
//             int k = N - i - j;
//             if (i * i + j * j == k * k)
//                     ret++;
//         }
//     }
//     cout << ret << endl;
//     system("pause");
//     return 0;
// }

// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// int main()
// {
//     int N;
//     cin >> N;
//     //int dp[N][N] = {0};
//     int dp[N];
//     memset(dp, 0, sizeof(dp));
//     int a[N], b[N];
//     for (size_t i = 0; i < N; i++)
//     {
//         cin >> a[i];
//     }
//     for (size_t i = 0; i < N; i++)
//     {
//         cin >> b[i];
//     }

//     for (int i = 1; i <= N; i++)
//     {
//         for (int j = 1; j <= N; j++)
//         {
//             if (a[i - 1] == b[j - 1])
//             {
//                 dp[i] = dp[i - 1] + 1;
//             }
//             else
//             {
//                 dp[i] = max(dp[i - 1], dp[i]);
//             }
//         }
//     }
//     printf("%d\n", N - dp[N]);
//     system("pause");
//     return 0;
// }