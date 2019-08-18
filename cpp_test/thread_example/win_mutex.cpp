#include <windows.h>
#include <iostream>
using namespace std;
int number = 1; //定义全局变量
HANDLE hMutex;  //定义互斥对象句柄
unsigned long __stdcall ThreadProc1(void *lp)
{
    while (number < 100)
    {
        WaitForSingleObject(hMutex, INFINITE);
        cout << "thread 1 :" << number << endl;
        ++number;
        _sleep(100);
        ReleaseMutex(hMutex);
    }
    return 0;
}

unsigned long __stdcall ThreadProc2(void *lp)
{
    while (number < 100)
    {
        WaitForSingleObject(hMutex, INFINITE);
        cout << "thread 2 :" << number << endl;
        ++number;
        _sleep(100);
        ReleaseMutex(hMutex);
    }
    return 0;
}

int main()
{
    hMutex = CreateMutex(NULL, false, "mutex"); //创建互斥对象
    CreateThread(NULL, 0, ThreadProc1, NULL, 0, NULL);
    CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);
    Sleep(10 * 1000);
    system("pause");
    return 0;
}
