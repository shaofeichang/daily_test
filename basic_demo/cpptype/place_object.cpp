#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A" << endl;
    }

private:
    ~A()
    {
        cout << "~A" << endl;
    }
};

class B
{
public:
    B()
    {
        cout << "B" << endl;
    }
    ~B()
    {
        cout << "~B" << endl;
    }

private:
    void* operator new(size_t sz){}
    void operator delete(void *sz){}
};

int main()
{

    A *a = new A;
    B b;
    cout << a <<endl;
    cout << &b <<endl;
    system("pause");
    return 0;
}