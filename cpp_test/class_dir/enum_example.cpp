#include <bits/stdc++.h>
using namespace std;

enum class Enumeration1
{
    Val1, // 0
    Val2, // 1
    Val3 = 100,
    Val4 /* = 101 */
};
// 指定类型
enum class Enumeration2 : long
{
    val1,
    val2 = 100,
    val3
}; // val2=100.000400 出错
#include <boost/type_index.hpp>
int main(int argc, char **argv)
{
    Enumeration2 en1 = Enumeration2::val3;
    cout << typeid(en1).name() << endl;
    using boost::typeindex::type_id_with_cvr;
    cout << type_id_with_cvr<decltype(en1)>().pretty_name() << endl;
    Enumeration1 my = Enumeration1::Val3;
    cout << static_cast<int>(my) << endl;
    cout << static_cast<double>(Enumeration2::val2) << endl;
    system("pause");
    return 0;
}