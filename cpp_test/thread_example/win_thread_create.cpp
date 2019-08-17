#include <iostream>
#include <Windows.h>
#include <process.h>
using namespace std;
/*
    uintptr_t _beginthreadex( // NATIVE CODE
        void *security, //线程安全属性
        unsigned stack_size, //线程的栈大小
        unsigned ( *start_address )( void * ),//线程函数
        void *arglist, //传递到线程函数中的参数
        unsigned initflag, //线程初始化标记
        unsigned *thrdaddr //线程ID
    );
*/
unsigned int _stdcall ThreadProc(LPVOID lpParameter)
{
    cout << "thread function ThreadProc!\n";
    return 0;
}

int main()
{
    _beginthreadex(NULL, 0, ThreadProc, 0, 0, NULL);

    Sleep(1000);
    cout << "main end!\n";
    system("pause");
    return 0;
}
