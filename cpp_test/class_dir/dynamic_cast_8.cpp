// dynamic_cast_8.cpp
// compile with: /GR /EHsc
#include <stdio.h>
#include <iostream>

struct A
{
    virtual void test()
    {
        printf_s("in A\n");
    }
};

struct B : A
{
    virtual void test()
    {
        printf_s("in B\n");
    }

    void test2()
    {
        printf_s("test2 in B\n");
    }
};

struct C : B
{
    virtual void test()
    {
        printf_s("in C\n");
    }

    void test2()
    {
        printf_s("test2 in C\n");
    }
};

void Globaltest(A &a)
{
    try
    {
        C &c = dynamic_cast<C &>(a);
        printf_s("in GlobalTest\n");
    }
    catch (std::bad_cast)
    {
        printf_s("Can't cast to C\n");
    }
}

int main()
{
    A *pa = new C;
    A *pa2 = new B;

    pa->test();

    B *pb = dynamic_cast<B *>(pa);
    if (pb)
        pb->test2();

    C *pc = dynamic_cast<C *>(pa2);
    if (pc)
        pc->test2();

    C ConStack;
    Globaltest(ConStack);

    // will fail because B knows nothing about C
    B BonStack;
    Globaltest(BonStack);
    A AonStack;
    Globaltest(AonStack);
  
    B* pb1 = new C;
    C* pcr = dynamic_cast<C*>(pb1);
    pcr->test2();
    B* pbr = dynamic_cast<B*>(pb1);
    pb1->test2();
    pb1->test();
    pbr->test();
    pbr->test2();
    A* par = dynamic_cast<A*>(pb1);
    par->test();
    system("pause");
    return 0;
}