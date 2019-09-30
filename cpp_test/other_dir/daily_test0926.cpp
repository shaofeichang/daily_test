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
void getmem(char *&p)
{
    p = (char*)malloc(100);
}
void Test(void)
{
    char *str = NULL;
    getmem(str);
    strcpy(str,"helloworld");
    printf(str);
    free(str);
}
void setarr(int *a)
{
    a[1] = 123;
}
int main()
{
    int aaa[10] = {1,2,3,4,5};
    setarr(aaa);
    Test();
    int num = 0x80000000;
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