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
    char a;
};

class DerA : public A
{
public:
    double cal(double a, double b) { return a + b + 1000; }
    double cala(double a, double b)
    {
        return cal(a, b);
    }
};
template<class T, int dim>
class ArrayClass
{
public:
    ArrayClass(T arr[dim]) {
        for (size_t i = 0; i < dim; i++)
        {
            arrc[i] = arr[i];
        }
        
    }
    ArrayClass(){}
private:
    T arrc[dim];
};

int main()
{
    int arr[10] = {1,2,3,4,5};
  // ArrayClass<int, 10> ac(arr);
    ArrayClass<int, 10> ac;
    cout << sizeof(ac) << endl;
    DerA dera;
    cout << dera.cal(12, 34) << endl;
    cout << dera.cala(123, 34) << endl;
    A *pa = new DerA;
    pa->setxy(12, 23);
    cout << pa->cal(123, 123) << endl;

    delete pa;
    system("pause");
    return 0;
}