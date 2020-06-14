#include <iostream>
using namespace std;

/// 汉诺塔问题解决方法
/// <param name="n">汉诺塔的层数</param>
/// <param name="a">承载最初圆盘的柱子</param>
/// <param name="b">起到中转作用的柱子</param>
/// <param name="c">移动到的目标柱子</param>

void HanNuo(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << "num " << n << "  " << a << " -> " << c << endl;
    }
    else
    {
        HanNuo(n - 1, a, c, b);
        cout << "num " << n << "  " << a << " -> " << c << endl;
        HanNuo(n - 1, b, a, c);
    }
}
int main()
{
    HanNuo(4, 'a', 'b', 'c');
    system("pause");
    return 0;
}