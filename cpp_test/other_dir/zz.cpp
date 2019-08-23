// sort algorithm example
#include <iostream>  // std::cout
#include <algorithm> // std::sort
#include <vector>    // std::vector

bool myfunction(int i, int j) { return (i < j); }

struct myclass
{
    bool operator()(int i, int j) { return (i < j); }
} myobject;
class A
{
public:
    int a;
};
int main()
{

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

    std::vector<std::vector<int>> vec;
    int num[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    for (int i = 0; i < 2; i++)
    {
        std::vector<int> temp;
        for (size_t j = i * 10; j < i * 10 + 10; j++)
            temp.push_back(num[j]);
        vec.push_back(temp);
    }
    vec.push_back({11,22});
    vec[1].push_back(111);
    std::vector<A> vecmy;
    A a1;
    A a2;
    vecmy.push_back(a1);
    vecmy.push_back(a2);
    std::cout << '\n';
    return 0;
}