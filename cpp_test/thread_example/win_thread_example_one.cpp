#include <iostream>
#include <Windows.h>
using namespace std;

DWORD WINAPI Fun1Proc(LPVOID lpParameter)
{
    cout << "thread function Fun1Proc!\n";

    return 0;
}
/*
    HANDLECreateThread(
    LPSECURITY_ATTRIBUTES lpThreadAttributes,//线程安全属性
    DWORD dwStackSize,//堆栈大小
    LPTHREAD_START_ROUTINE lpStartAddress,//线程函数
    LPVOID lpParameter,//线程参数
    DWORD dwCreationFlags,//线程创建属性
    LPDWORD lpThreadId//线程ID
    );
 */
int main()
{
    HANDLE hThread1 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);
    CloseHandle(hThread1);

    Sleep(1000);
    cout << "main end!\n";
    system("pause");
    return 0;
}