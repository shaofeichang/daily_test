#include <iostream>
using namespace std;

class A
{
public:
    virtual double cal(double a, double b) { return a + b; }
    void setxy(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

private:
    int x, y;
};

class DerA : public A
{
public:
    double cal(double a, double b) { return a + b + 1000 + x + y; }
    double cala(double a, double b)
    {
        return cal(a, b);
    }
};

int main()
{
    DerA dera;
    cout << dera.cal(12, 34) << endl;
    cout << dera.cala(123, 34) << endl;
    A *pa = new DerA;
    pa->setxy(12,23);
    cout << pa->cal(123, 123) << endl;

    delete pa;
    system("pause");
    return 0;
}