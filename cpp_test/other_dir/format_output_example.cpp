#include <stdio.h>
#include <bitset>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

void c_format()
{
    printf("35 in oct:  %05o\n", 35); //按八进制格式输出，保留5位高位补零
    printf("35 in dec : %03d\n", 35); //按十进制格式输出，保留3位高位补零
    printf("35 in hex : %05x\n", 35); //按十六进制格式输出，保留5位高位补零
}
void cpp_format()
{
    cout << "35 in oct :" << std::oct << 35 << endl;
    cout << "35 in dec :" << std::dec << 35 << endl;
    cout << "35 in hex :" << std::hex << 35 << endl;
    cout << "35 in bit : " << bitset<8>(35) << endl; //<8>：表示保留8位输出
}
void stringstream_format()
{
    string s = "20";
    int a;
    stringstream ss;
    ss << hex << s;
    ss >> a;
    cout << a << endl;

    ss.clear();

    string s1, s2;
    ss << oct << a;
    ss >> s1;
    cout << s1 << endl;
    ss.clear();
    ss << hex << a;
    ss >> s2;
    cout << s2 << endl;
}

void sscanf_example()
{
    char sentence[] = "Rudolph is 12 years old";
    char str[20];
    int i;

    sscanf(sentence, "%s %*s %d", str, &i);
    printf("%s -> %d\n", str, i);
}

void precision()
{
    const long double pi = std::acos(-1.L);
    std::cout << "default precision (6): " << pi << '\n'
              << "std::setprecision(10): " << std::setprecision(10) << pi << '\n'
              << "max precision:         "
              << std::setprecision(std::numeric_limits<long double>::digits10 + 1)
              << pi << '\n';
}
void setwex()
{
    std::cout << "no setw:" << 42 << '\n'
              << "setw(6):" << std::setw(6) << 42 << '\n'
              << "setw(6), several elements: " << 89 << std::setw(6) << 12 << 34 << '\n';
    std::istringstream is("hello, world");
    char arr[10];
    is >> std::setw(6) >> arr;
    std::cout << "Input from \"" << is.str() << "\" with setw(6) gave \""
              << arr << "\"\n";
}

void fixedex()
{
    std::cout << "The number 0.01 in fixed:      " << std::fixed << 0.01 << '\n'
              << "The number 0.01 in scientific: " << std::scientific << 0.01 << '\n'
              << "The number 0.01 in hexfloat:   " << std::hexfloat << 0.01 << '\n'
              << "The number 0.01 in default:    " << std::defaultfloat << 0.01 << '\n';
    double f;
    std::istringstream("0x1P-1022") >> std::hexfloat >> f;
    std::cout << "Parsing 0x1P-1022 as hex gives " << f << '\n';
}
int main()
{
    fixedex();
    setwex();
    precision();
    sscanf_example();
    stringstream_format();
    c_format();
    cpp_format();
    system("pause");
    return 0;
}