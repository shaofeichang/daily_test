#pragma pack(1)
#include <stdio.h>
#include <iostream>
using namespace std;
struct inunion
{
    unsigned char identify;
    int num1;   //4个字节    0x0102  十六进制： 0x00000102    二进制： 00000000 00000000 00000001 00000002
    short num2; //2个字节    0x0203  十六进制： 0x0203        二进制： 00000002 00000003
    short num3; //2个字节
};
union unsend23d {
    unsigned char data23d[9]; //8个字节
    inunion structinunion;
};
unsigned char g_SendData[256];

struct sendData
{
    int data1;
    int data2;
    short data3;
};
#include <string.h>
int main()
{
    sendData sd = {123, 345, 55};
    unsigned char sdchar[10];
    // int ret = snprintf(sdchar, 128, "hello");
    memcpy(sdchar, &sd, sizeof(sd));
    sendData sd1;
    memcpy(&sd1, sdchar, sizeof(sd));
    cout << "sizeof(sdchar) = " << sizeof(sdchar) <<" sizeof(sd) = "<<sizeof(sd)<<endl;
    
    int num1 = 0x01020304;
    int num3 = 0x09080706;
    g_SendData[0] = (unsigned char)num1;
    g_SendData[1] = (unsigned char)(num1 >> 8);
    g_SendData[2] = (unsigned char)(num1 >> 16);
    g_SendData[3] = (unsigned char)(num1 >> 24);

    int numreceive = g_SendData[0] + (g_SendData[1] << 8) + (g_SendData[2] << 16) + (g_SendData[3] << 24);

    unsend23d un;
    un.structinunion.identify = 0x01;
    cout << sizeof(un) << endl;
    un.structinunion.num1 = 0x28723112;
    un.structinunion.num2 = 0x0203;
    un.structinunion.num3 = 0x0304;
    for (size_t i = 0; i < 8; i++)
    {
        printf("0x %#x  ", un.data23d[i]);
        //  cout<<(int)un.data23d[i] <<" ";
    }
    cout << endl;
    system("pause");
    return 0;
}
