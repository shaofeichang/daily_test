#include <bits/stdc++.h>
using namespace std;
using DWORD = long long;
class TestA
{
public:
    TestA() {}
    ~TestA() {}
    int a;
};
int main()
{
    int num = 0x80000000;INT_MIN
    cout << sizeof(DWORD) << endl;
    TestA testa;
    int a = 123;
    int *p = &a;
    cout << sizeof(p) << endl;
    cout << &testa << endl;
    cout << (int *)(&testa) << endl;
    system("pause");
    return 0;
}