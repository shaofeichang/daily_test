#include <iostream>
using namespace std;
class X
{
public:
    X();
    virtual ~X();
    virtual void rotate();
};

X::X()
{
    cout << " X construct" << endl;
}
X::~X()
{
    cout << "X deconstruct" << endl;
}
void X::rotate()
{
    cout << "x rotate" << endl;
}
class Z : public X
{
public:
    Z()
    {
        cout << "Z" << endl;
    };
    ~Z()
    {
        cout << "~Z" << endl;
    };
    void rotate()
    {
        cout << "Z rotate" << endl;
    };
};
void rotate(X datum, X *pointer, X &referece)
{
    cout << &datum << "  " << pointer << "  " << &referece << endl;
    (*pointer).rotate();
    referece.rotate();
    datum.rotate();
}
int main()
{
    Z z;
    rotate(z, &z, z);
    system("pause");
    return 0;
}