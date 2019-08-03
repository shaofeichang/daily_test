#include <stdio.h>
#include <bitset>
#include <string>
#include <iostream>
#include <sstream>
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
int main()
{
    sscanf_example();
    stringstream_format();
    c_format();
    cpp_format();
    system("pause");
    return 0;
}