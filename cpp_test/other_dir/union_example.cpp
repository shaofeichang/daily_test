#include <iostream>
//#pragma pack(1)
union UnionTest {
    UnionTest() : i(10){};
    int i;
    double d;
};

static union {
    int i;
    double d;
};
union Num {
    int i;
    char c[4];
};
struct BitExample
{
    unsigned int numa : 8;
    unsigned int numb : 4;//4
    int numc;      // 4
    int numca[33]; // 33 * 4 = 132
    char cnumd; // 4
};

struct BitExample1
{
    unsigned int numa : 16; // 4
    unsigned int numb : 16; // 4
    unsigned int numc : 16; // 4
    char cnumd; // 1
};
int main()
{
    int BitExampleSize1 = sizeof(BitExample1);
    std::cout << "BitExampleSize1 : " << BitExampleSize1 << std::endl; //
    int BitExampleSize = sizeof(BitExample);
    std::cout << "BitExampleSize : " << BitExampleSize << std::endl; // 144
    Num num;
    num.c[0] = 10;
    num.c[1] = 1;
    num.c[3] = 1;
    // 00000001 00001010
    std::cout << num.i << std::endl;
    UnionTest u;

    union {
        int i;
        double d;
    };

    std::cout << u.i << std::endl; // 输出 UnionTest 联合的 10

    ::i = 20;
    std::cout << ::i << std::endl; // 输出全局静态匿名联合的 20

    i = 30;
    std::cout << i << std::endl; // 输出局部匿名联合的 30

    system("pause");
    return 0;
}