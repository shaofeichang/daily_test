// shared_ptr::get example
#include <iostream>
#include <memory>
struct C
{
    int num1;
    void printnum() { std::cout << "num1: " << num1 << std::endl; }
    C(int n):num1(n) { std::cout << "C" << std::endl; }
    ~C() { std::cout << "~C" << std::endl; }
};
int main()
{
    int *p = new int(10);
    std::shared_ptr<int> a(p);

    if (a.get() == p)
        std::cout << "a and p point to the same location\n";
    
    // three ways of accessing the same address:
    std::cout << *a.get() << "\n";
    std::cout << *a << "\n";
    std::cout << *p << "\n";
    std::shared_ptr<C> ssp(new C(100));
    C *cp = new C(1234);
    std::shared_ptr<C> ptrc(cp);
    cp->printnum();
    ptrc->printnum();
    ptrc.get()->printnum();
    (*ptrc).printnum();
    (*cp).printnum();
    return 0;
}