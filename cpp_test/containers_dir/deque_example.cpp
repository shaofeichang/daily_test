// constructing deques
#include <iostream>
#include <deque>
int main()
{
    {
        std::cout << "Example1 construct function:\n";
        unsigned int i;
        // constructors used in the same order as described above:
        std::deque<int> first;                               // empty deque of ints
        std::deque<int> second(4, 100);                      // four ints with value 100
        std::deque<int> third(second.begin(), second.end()); // iterating through second
        std::deque<int> fourth(third);                       // a copy of third
        // the iterator constructor can be used to copy arrays:
        int myints[] = {16, 2, 77, 29};
        std::deque<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
        std::cout << "The contents of fifth are: ";
        for (std::deque<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
            std::cout << ' ' << *it;
        std::deque<int> sixth{1, 2, 3, 4};
        std::cout << "\nThe contents of sixth are: ";
        for (std::deque<int>::iterator it = sixth.begin(); it != sixth.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    {
        std::cout << "Example2 assign function:\n";
        std::deque<int> first;
        std::deque<int> second;
        std::deque<int> third;
        first.assign(7, 100); // 7 ints with a value of 100
        std::deque<int>::iterator it;
        it = first.begin() + 1;
        second.assign(it, first.end() - 1); // the 5 central values of first
        int myints[] = {1776, 7, 4};
        third.assign(myints, myints + 3); // assigning from array.
        std::cout << "Size of first: " << int(first.size()) << '\n';
        std::cout << "Size of second: " << int(second.size()) << '\n';
        std::cout << "Size of third: " << int(third.size()) << '\n';
    }
    system("pause");
    return 0;
}