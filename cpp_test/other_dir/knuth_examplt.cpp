#include <iostream>
#include <time.h>
using namespace std;
// 从0....n-1中随机等概率的输出m个不重复的数
void knuth(int n, int m)
{
    srand((unsigned int)time(0));
    for (int i = 0; i < n; i++)
    {
        if (rand() % (n - i) < m)
        {
            cout << i << endl;
            (m--);
        }
    }
}
int main()
{
    knuth(10000, 10);
    system("pause");
    return 0;
}