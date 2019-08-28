#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
int main()
{
    {
        int a = 1, b = 1, c = 1;
        auto m1 = [a, &b, &c]() mutable {
            auto m2 = [a, b, &c]() mutable {
                std::cout << a << b << c << '\n';
                a = 4; b = 4; c = 4;
            };
            a = 3; b = 3; c = 3;
            m2();
        };

        a = 2; b = 2; c = 2;
        m1();                             // 调用 m2() 并打印 123
        std::cout << a << b << c << '\n'; // 打印 234
    }
    std::vector<int> c = {1, 2, 3, 4, 5, 6, 7};
    int x = 5;
    c.erase(std::remove_if(c.begin(), c.end(), [x](int n) { return n < x; }), c.end());

    std::cout << "c: ";
    std::for_each(c.begin(), c.end(), [](int i) { std::cout << i << ' '; });
    std::cout << '\n';

    // 闭包的类型不能被指名，但可用 auto 提及
    // C++14 起，lambda 能拥有自身的默认实参
    auto func1 = [](int i = 6) { return i + 4; };
    std::cout << "func1: " << func1() << '\n';

    // 与所有可调用对象相同，闭包能可以被捕获到 std::function 之中
    // （这可能带来不必要的开销）
    std::function<int(int)> func2 = [](int i) { return i + 4; };
    std::cout << "func2: " << func2(6) << '\n';
    system("pause");
    return 0;
}