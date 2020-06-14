// array::begin example
#include <iostream>
#include <array>
#include <cstring>
int main()
{
    {
        std::cout<<"Example1  begin:\n";
        std::array<int, 5> myarray = {2, 16, 77, 34, 50};
        std::cout << "myarray contains:";
        for (auto it = myarray.begin(); it != myarray.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    {
        std::cout<<"Example2  at:\n";
        std::array<int, 10> myarray;
        for (int i = 0; i < 10; i++)
            myarray.at(i) = i + 1;
        std::cout << "myarray contains: ";
        for (int i = 0; i < 10; i++)
        {
            std::cout << ' ' << myarray.at(i);
        }
        std::cout << "\n";
    }
    {
        std::cout<<"Example3  data:\n";
        const char *cstr = "Test string";
        std::array<char, 12> charray;
        std::memcpy(charray.data(), cstr, 12);
        std::cout << charray.data() << '\n';
        std::cout << "size: " << charray.size() << '\n';
        std::cout << "max_size: " << charray.max_size() << '\n';
    }
    {
        std::cout<<"Example4  swap:\n";
        std::array<int, 5> first = {10, 20, 30, 40, 50};
        std::array<int, 5> second = {11, 22, 33, 44, 55};
        first.swap(second);
        std::cout << "first:";
        for (int &x : first)
            std::cout << ' ' << x;
        std::cout << '\n';
        std::cout << "second:";
        for (int &x : second)
            std::cout << ' ' << x;
        std::cout << '\n';
    }
    system("pause");
    return 0;
}