// sort algorithm example
#include <iostream>  // std::cout
#include <algorithm> // std::sort
#include <vector>    // std::vector

bool myfunction(int i, int j) { return (i < j); }

struct myclass
{
    bool operator()(int i, int j) { return (i < j); }
} myobject;

int funcA(int i = 10)
{
    std::cout << "FUNCA  " << i << std::endl;
    return i;
}

class A
{
public:
    virtual int func(int i = 1)
    {
        std::cout << "CLASS A" << std::endl;
        return i;
    }
    virtual ~A() { std::cout << "~A" << std::endl; }
};
class B : public A
{
public:
    virtual int func(int i = 10)
    {
        std::cout << "CLASS B" << i << std::endl;
        return i;
    }
    virtual ~B() { std::cout << "~B" << std::endl; }
};

int main()
{
    A *pb = new B;
    std::cout<<pb->func()<<std::endl;
    delete pb;
    std::cout << funcA() << std::endl;

    int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};
    std::vector<int> myvector(myints, myints + 8); // 32 71 12 45 26 80 53 33
    // using default comparison (operator <):
    std::sort(myvector.begin(), myvector.begin() + 4); //(12 32 45 71)26 80 53 33

    // using function as comp
    std::sort(myvector.begin() + 4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

    // using object as comp
    std::sort(myvector.begin(), myvector.end(), myobject); //(12 26 32 33 45 53 71 80)

    // print out content:
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;

    std::vector<std::vector<int>> doublevec = {{12, 351, 15},
                                               {145, 11, 513},
                                               {545, 1, 513, 34},
                                               {12, 35, 11},
                                               {545, 23, 52}};
    std::sort(doublevec.begin(), doublevec.end());

    std::cout << '\n';
    return 0;
}