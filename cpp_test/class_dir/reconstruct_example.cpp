#include <bits/stdc++.h>
using namespace std;
/**
 * （1）成员函数运算符重载时，运算符的左值为调用对象，右值为参数对象，举个例子，a,b均是类A的对象，重载“+”实现a+b，可以将其认为是：a对象调用“+”函数，函数的参数为b对象；
 *  而在事实上，a对象和b对象都是这个“+”函数的参数，只不过a对象被隐式调用，由this指针所绑定。因此成员函数运算符重载的显式参数比实际运算参数少一个；
 * 而在非成员函数运算符重载中，必须将操作数全部显式添加在参数列表中，运算符左值为第一个参数，运算符右值为第二个参数。
 * （2）成员函数运算符重载时，运算符左值类型必须为所在类类型；而非成员函数运算符重载则不必。
 * 一般来说，对于双目运算符，应当将其重载为非成员函数（友元函数），而对于单目运算符，则应将其重载为成员函数。
 * 但这也不是绝对的，双目运算符中，“=”、“[]”、“->”和“()”是必须重载为成员函数的。而"<<"运算符由于其第一个运算符必须是ostream的，所以只能重载为友元函数。
 * 个人认为，“=”、“[]”、“->”和“（）”运算符之所以必须作为类成员函数进行重载，
 * 其原因是因为：在成员函数重载时，会自动将this指针绑定到左值上，这样也就强制规定了运算符左值的类型，
 * 如果不这样，而是通过非成员函数进行重载，那么很有可能会出现类似“3=a”、“3[a]”、“3->a”以及“3(a)”的情况，
 * 单从运算符重载函数上说，这些似乎都是对的，但是实际上这些在语法上都是错误的，是需要坚决避免的，为了避免出现这些情况，就应当将这四种运算符重载限定在成员函数中。
 */
class Stu
{
public:
    int age;
    string name;
    Stu(){};
    Stu(int a, string b)
    {
        age = a;
        name = b;
    }
    ~Stu() {}
    Stu operator+(const Stu &ss) const //成员函数运算符重载
    {
        Stu n;
        n.age = this->age + ss.age; //this可去掉
        n.name = ss.name;
        return n;
    }
    bool operator>(const Stu &ss) const
    {
        return this->age > ss.age;
    }
    bool operator<(const Stu &ss) const
    {
        return this->age < ss.age;
    }
    friend int operator+(const int s1, const Stu &s2);
};
int operator+(const int s1, const Stu &s2) //非成员函数运算符重载
{
    int n;
    n = s1 * s2.age;
    return n;
}
int main()
{
    Stu s(3, "lili");
    Stu s2(5, "yaya");
    cout << (s < s2) << endl;
    s = s + s2;
    int x = s.age + s2;
    cout << s.age << " " << s.name << " " << x << endl;
    system("pause");
    return 0;
}
//运行结果
// Stu constructor1 called !Stu constructor1 called !Stu constructor called !Stu destructor called !8 yaya 40 Stu destructor called !Stu destructor called !
