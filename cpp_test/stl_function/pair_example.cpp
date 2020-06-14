#include <tuple>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
std::pair<double, std::string> get_student(int id)
{
    if (id == 0)
        return std::make_pair(3.8, "Lisa Simpson");
    if (id == 1)
        return std::make_pair(2.9, "Milhouse Van Houten");
    if (id == 2)
        return std::make_pair(1.7, "Ralph Wiggum");
    throw std::invalid_argument("id");
}

int main()
{
    {
        std::vector<std::pair<int, std::string>> v1 = {{2, "baz"},
                                                       {2, "bar"},
                                                       {1, "foo"}};
        std::sort(v1.begin(), v1.end());

        std::vector<std::pair<int, std::string>> v2 = {{3, "baz"},
                                                      {4, "bar"},
                                                      {5, "foo"}};
        std::sort(v2.begin(), v2.end());
        std::swap(v1, v2);
        std::cout << "V1" << std::endl;                                                      
        for (auto p : v1)
        {
            std::cout << "(" << p.first << "," << p.second << ")\n";
        }
        std::cout << "V2" << std::endl;                                                      
        for (auto p : v2)
        {
            std::cout << "(" << p.first << "," << p.second << ")\n";
        }
    }
    {
        std::vector<std::pair<int, std::string>> vec;
        vec.push_back(std::pair<int, std::string>(1, "hello"));
        vec.push_back(std::pair<int, std::string>(2, "world"));
        vec.push_back(std::make_pair(3, "china"));

        for (auto i : vec)
        {
            std::cout << i.first << "   " << i.second << std::endl;
        }
        std::cout << "end pair" << std::endl;
    }
    {
        auto student0 = get_student(0);
        std::cout << "ID: 0, "
                  << "GPA: " << std::get<0>(student0) << ", "
                  << "name: " << std::get<1>(student0) << '\n';

        double gpa1;
        char grade1;
        std::string name1;
        std::tie(gpa1, name1) = get_student(1);
        std::cout << "ID: 1, "
                  << "GPA: " << gpa1 << ", "
                  << "name: " << name1 << '\n';

        // C++17 结构化绑定：
        auto [gpa2, name2] = get_student(2);
        std::cout << "ID: 2, "
                  << "GPA: " << gpa2 << ", "
                  << "name: " << name2 << '\n';
    }
    system("pause");
    return 0;
}