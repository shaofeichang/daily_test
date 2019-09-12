#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> vec;
int M, N;

int getLength(int row, int col)
{
    int res = 1;
    if (row >= M || row < 0 || col >= N || col < 0 || vec[row][col] != 1)
        return 0;
    vec[row][col] = 0;
    res += getLength(row - 1, col) + getLength(row + 1, col) + getLength(row, col + 1) + getLength(row, col - 1);
    return res;
}
int main()
{

    cin >> M;
    getchar();
    cin >> N;
    for (size_t i = 0; i < M; i++)
    {
        vector<bool> row;
        for (size_t j = 0; j < N; j++)
        {
            bool temp;
            cin >> temp;
            row.push_back(temp);
            getchar();
        }
        vec.push_back(row);
    }
    int res = INT_MIN;
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            res = max(getLength(i, j), res);
        }
    }
    cout << res << endl;
    system("pause");
    return 0;
}
//  100 180 310 40 535 695
// 100,180,310,40,535,695
/*

4,5
1,1,1,0,0
0,0,1,0,0
1,1,0,0,0
1,0,0,0,0

*/
vector<int> vec;
int num;
while (cin >> num)
{
    vec.push_back(num);
    getchar();
}
int sum = 0;
for (size_t i = 0; i < vec.size() - 1; i++)
{
    if(vec[i + 1] < vec[i] ){
        sum += vec[i] - vec[i+1];
    }
}
cout << sum;