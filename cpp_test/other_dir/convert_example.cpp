#include <iostream>
#include <string>
using namespace std;
//转换操作符
class Dog
{
public:
    Dog(string name, int a, double w) : name(name), age(a), weight(w) {}
    //转换函数
    //1.必须是成员函数
    //2.形参表必须是空的
    //3.不能指定返回类型
    //4.必须显示返回一个指定类型的值
    //5.不应该改变被转换的对象，通常定义为const
    operator int() const
    {
        return age;
    }
    operator double() const
    {
        return weight;
    }
    operator string() const
    {
        return name;
    }

private:
    int age;
    double weight;
    string name;
};

int main()
{
    Dog d("Bill", 6, 12.2);
    int a = d;
    double aa = d;
    string thisname = d;
    cout << "a:" << a << " ; "
         << "b: " << aa << " name:" << thisname << endl;

    Dog *nd = new Dog("thishsi", 11, 123.4546);
    int a1 = *nd;
    double aa1 = *nd;
    string thisname1 = *nd;
    cout << "a:" << a1 << " ; "
         << "b: " << aa1 << " name:" << thisname1 << endl;
    delete nd;
    system("pause");
    return 0;
}