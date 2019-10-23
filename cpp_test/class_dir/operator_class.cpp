#include <bits/stdc++.h>
using namespace std;

class Add
{
public:
    Add(int n) : num(n) {}
    ~Add() { cout << "~A" << endl; }
    void operator++() { this->num++; }
    void operator++(int) { ++*this; }
    int getNum() { return this->num; }

private:
    int num;
};
template <class Iterator, class T>
Iterator findT(Iterator begin, Iterator end, const T &value)
{
    while (begin != end && (*begin).getNum() != value)
        ++begin;
    return begin;
}
int main()
{
    vector<int> va(4);
    int n = 3;
    iota(va.begin(), va.end(), n);
    Add addarr[] = {{Add(1)}, {Add(2)}, {Add(3)}, {Add(4)}};
    cout << addarr->getNum() << endl;
    Add *fd = findT(addarr, addarr + 3, 3);
    if (fd)
        cout << fd->getNum() << endl;

    cout << endl;
    system("pause");
    return 0;
}