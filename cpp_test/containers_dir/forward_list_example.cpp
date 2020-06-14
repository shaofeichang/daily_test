// forward_list constructors
#include <iostream>
#include <forward_list>
template <typename S>
void print(const S &s)
{
    for (const auto &p : s)
    {
        std::cout << "(" << p << ") ";
    }
    std::cout << '\n';
}
int main()
{
    // constructors used in the same order as described above:
    {
        std::forward_list<int> first;                               // default: empty
        std::forward_list<int> second(3, 77);                       // fill: 3 seventy-sevens
        std::forward_list<int> third(second.begin(), second.end()); // range initialization
        std::forward_list<int> fourth(third);                       // copy constructor
        std::forward_list<int> fifth(std::move(fourth));            // move ctor. (fourth wasted)
        std::forward_list<int> sixth = {3, 52, 25, 90};             // initializer_list constructor
    }
    // assign
    {
        std::forward_list<int> first;
        std::forward_list<int> second;
        first.assign(4, 12);
        second.assign(first.begin(), first.end());

        first.assign({22, 44, 55});
        print(first);
    }
    {
        std::forward_list<int> mylist = {20, 30, 40, 50};
        mylist.insert_after(mylist.before_begin(), 11);
        std::cout << "mylist contains:";
        for (int &x : mylist)
            std::cout << ' ' << x;
        std::cout << '\n';
    }
    // sort
    {
        std::forward_list<int> mylist = {22, 13, 4, 62, 41, 44};
        mylist.sort();
        print(mylist);

        mylist.sort(std::greater<int>());
        print(mylist);

        mylist.sort(std::greater_equal<int>());
        print(mylist);
    }
    system("pause");
    return 0;
}