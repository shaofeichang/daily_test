#include <iostream>

using namespace std;
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
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    //int dp[N][N] = {0};
    int dp[N];
    memset(dp, 0, sizeof(dp));
    int a[N], b[N];
    for (size_t i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    for (size_t i = 0; i < N; i++)
    {
        cin >> b[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i] = dp[i-1] + 1;
            }
            else
            {
                dp[i] = max(dp[i - 1], dp[i]);
            }
        }
    }
    printf("%d\n", N - dp[N]);
    system("pause");
    return 0;
}