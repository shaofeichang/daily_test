#include <boost/progress.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
int main()
{
    std::vector<std::string> v(100);
    std::ofstream fs("test.txt");
    boost::progress_display pd(v.size());
    std::vector<std::string>::iterator pos;
    for (pos = v.begin(); pos != v.end(); pos++)
    {
        fs << *pos << std::endl;
        ++pd;
    }
    boost::progress_display pd1(v.size(), std::cout, "%%%", "+++", "???");
    for (auto i : v)
    {
        fs << i << std::endl;
        ++pd1;
    }
    system("pause");
    return 0;
}