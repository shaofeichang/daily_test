// constructing multisets
#include <iostream>
#include <set>

bool fncomp(int lhs, int rhs) { return lhs > rhs; }

struct classcomp
{
    bool operator()(const int &lhs, const int &rhs) const
    {
        return lhs < rhs;
    }
};

int main()
{
    {
        std::set<int> first; // empty set of ints

        int myints[] = {10, 20, 20, 30, 40, 50};
        std::set<int> second(myints, myints + 5); // range

        std::set<int> third(second); // a copy of second

        std::set<int> fourth(second.begin(), second.end()); // iterator ctor.

        std::set<int, classcomp> fifth; // class as Compare

        bool (*fn_pt)(int, int) = fncomp;
        std::set<int, bool (*)(int, int)> sixth(fn_pt); // function pointer as Compare
    }
    {
        std::multiset<int> first; // empty multiset of ints

        int myints[] = {10, 20, 30, 20, 20};
        std::multiset<int> second(myints, myints + 5); // pointers used as iterators

        std::multiset<int> third(second); // a copy of second

        std::multiset<int> fourth(second.begin(), second.end()); // iterator ctor.

        std::multiset<int, classcomp> fifth; // class as Compare
        fifth.insert(second.begin(), second.end());
        bool (*fn_pt)(int, int) = fncomp;
        std::multiset<int, bool (*)(int, int)> sixth(fn_pt); // function pointer as Compare
        sixth.insert(second.begin(), second.end());
    }

    return 0;
}