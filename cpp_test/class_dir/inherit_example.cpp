#include <bits/stdc++.h>
using namespace std;
/**
 *                   public                          public
 *类成员访问限定符    protected         三种继承关系   protected
 *                   private                         private
 * 
 */
class A
{
public:
    A() { cout << "CONSTRUCT A" << endl; }
    virtual ~A() { cout << "DECONSTRUCT A" << endl; };
    A(int n1, int n2, int n3) : num1(n1), num2(n2), numA(n3 * 2) { cout << "A: " << typeid(this).name() << endl; };
    virtual void printNum() { cout << "A: "
                                   << "NUM1 NUM2:  " << num1 << "  " << num2 << endl; }
    virtual void APrintNum() { cout << "A: "
                                    << "NUM1 NUM2:  " << num1 << "  " << num2 << endl; }
    void APrintNum1() { cout << "A: "
                             << "NUM1 NUM2 NUMA:  " << num1 << "  " << num2 << "  " << numA << endl; }
    int numA;
    friend A operator+(A &a1, A &a2);

private:
    int num1;
    int num2;
};
A operator+(A &a1, A &a2)
{
    A tp;
    tp.num1 = a1.num1 + a2.num1;
    tp.num2 = a1.num2 + a2.num2;
    tp.numA = a1.numA + a2.numA;
    return tp;
}
class InA : public A
{
public:
    InA() { cout << "CONSTRUCT INA" << endl; }
    virtual ~InA() { cout << "DECONSTRUCT INA" << endl; }
    InA(int n1, int n2, int n3) : num1(n1), A(n1, n2, n3), num3(n3) { cout << "INA: " << typeid(this).name() << endl; }
    virtual void printNum() { cout << "INA: "
                                   << "NUM1 A::numA NUM3:  " << num1 << "  " << A::numA << "   " << num3 << endl; }

private:
    int num1;
    int num3;
};
template<class T>
typename T::value_type
printhello(T num)
{
    return num;
}
int main()
{
    cout << printhello(1324)<<endl;
    A a1(1, 2, 3);
    A a2(10, 20, 30);
    A a3 = a1 + a2;
    a3.APrintNum1();

    InA ia1(1, 2, 3);
    InA ia2(10, 20, 30);
    InA ia3(2, 3, 4); // = ia1 + ia2;
    ia3.printNum();
    ia3.APrintNum1();

    A *ptra1 = new InA(1, 2, 3);
    ptra1->printNum();
    A *ptra = dynamic_cast<A *>(ptra1);
    if (!ptra1)
        cout << "ERROR" << endl;
    else
        ptra->printNum();
    A *ptra2 = (A *)(ptra1);
    ptra2->printNum();

    InA *inaPtr = new InA(11, 22, 33);
    inaPtr->printNum();
    A *inPtr = nullptr;
    if (inPtr = dynamic_cast<A *>(inaPtr))
    {
        cout << "INinNUMA:  " << inPtr->numA << endl;
        inPtr->APrintNum1();
    }
    else
        cout << "Dynamic ERR" << endl;
    delete ptra1;
    delete inaPtr;
    /*
    InA *ina = new InA(11, 22, 33);
    ina->printNum();
    A *inaPtr = nullptr;
    if (inaPtr = dynamic_cast<A *>(ina))
    {
        inaPtr->APrintNum1();
        inaPtr->APrintNum();
        inaPtr->printNum();
    }
    else
    {
        cout << "DYNAMIC CAST" << endl;
    }*/
    system("pause");
    return 0;
}
