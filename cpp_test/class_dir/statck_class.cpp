#include <iostream>
using namespace std;

class ClassA
{
public:
    ClassA(int n) : num(n)
    {
        cout << "  CLASSA" << endl;
    }
    ~ClassA() 
    { 
        cout << " ~CLASSA " << endl; 
    }
    void pirntfNum() 
    {
        cout << "num = " << num <<endl;
    }
private:
    int num;
};

int main()
{

    ClassA classa(123);
    (&classa)->pirntfNum();

    ClassA *classb = new ClassA(456);
    classb->pirntfNum();
    cout << "&classa = " << &classa << endl;
    cout << " classb = " << classb <<endl;
    cout << "&classb = " << &classb <<endl;
    delete classb;
    system("pause");
    return 0;
}
