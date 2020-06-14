#include <windows.h>
#include <iostream>
using namespace std;
int number = 1; //定义全局变量
HANDLE hEvent;  //定义事件句柄
unsigned long __stdcall ThreadProc1(void *lp)
{
    while (number < 100)
    {
        WaitForSingleObject(hEvent, INFINITE); //等待对象为有信号状态
        cout << "thread 1 :" << number << endl;
        ++number;
        _sleep(100);
        SetEvent(hEvent);
    }
    return 0;
}

unsigned long __stdcall ThreadProc2(void *lp)
{
    while (number < 100)
    {
        WaitForSingleObject(hEvent, INFINITE); //等待对象为有信号状态
        cout << "thread 2 :" << number << endl;
        ++number;
        _sleep(100);
        SetEvent(hEvent);
    }
    return 0;
}

int main()
{
    CreateThread(NULL, 0, ThreadProc1, NULL, 0, NULL);
    CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);
    hEvent = CreateEvent(NULL, FALSE, TRUE, "event");
    Sleep(10 * 1000);
    system("pause");
    return 0;
}
