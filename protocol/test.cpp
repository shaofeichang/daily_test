#include "radar_struct.h"
#include <bits/stdc++.h>
using namespace std;

struct ptrData
{
    int da1;
    double da2;
};
struct Data
{
    int num1;
    double num2;
    char *cptr;
};
template <class T1>
bool memcpy_s_send(unsigned char *buff, int bufflength, T1 &t1, int size)
{
    int sochar = sizeof(char *);
    int templen = sizeof(t1) - sochar;
    int temp1 = memcpy_s(buff, bufflength, &t1, templen);
    int temp2 = memcpy_s(buff + templen, bufflength - templen, t1.cptr, size);
    return ~(temp1 || temp2);
}
template <class T1, class T2>
bool memcpy_s_recv(unsigned char *buff, int bufflength, T1 &t1, T2 &t2, int size)
{
    int sochar = sizeof(char *);
    int templen = sizeof(t1) - sochar;
    int temp1 = memcpy_s(&t1, templen, buff, templen);
    int temp2 = memcpy_s(t2, size, buff + templen, size);
    return ~(temp1 || temp2);
}
int main()
{
    // ControlOutput Control;
    // Control.tarDamVerInfo = {132, 456};
    // Control.tarTrueValInfo = {1,
    //                           {1, 2, 11, 22, 33, 11, 22, 33, 11, 22, 33, 1, 1, 1, 1}};
    // unsigned char buffer[sizeof(Control)];
    // cout<<sizeof(Control)<<endl;
    // int i = memcpy_s(buffer, sizeof(Control), &Control, sizeof(Control));
    // if (i < 0)
    //     cout << "ERROR" << endl;
    // ControlOutput con;
    // int j = memcpy_s(&con, sizeof(con), buffer, sizeof(con));

    Data da;
    ptrData pd[3];
    pd[0].da1 = 11;
    pd[0].da2 = 11.11;
    pd[1].da1 = 22;
    pd[1].da2 = 22.22;
    pd[2].da1 = 33;
    pd[2].da2 = 33.33;
    da.num1 = 123;
    da.num2 = 456.456;
    da.cptr = (char *)pd;

    unsigned char buff[1024];
    // memcpy_s(buff, 1024, &da, sizeof(da) - 4);
    // memcpy_s(buff + sizeof(da) - 4, 1024 - sizeof(da) + 4, da.cptr, sizeof(pd));
    memcpy_s_send(buff, 1024, da, 3*sizeof(ptrData));
    Data ra;
    ptrData *pa1 = new ptrData[3];
    // memcpy_s(&ra, sizeof(ra) - 4, buff, sizeof(ra) - 4);
    // memcpy_s(pa1, sizeof(pd), buff + sizeof(da) - 4, sizeof(pd));
    // ptrData *pa1 = ((ptrData *)(ra.cptr));

    memcpy_s_recv(buff, 1024, ra, pa1, 3*sizeof(ptrData));

    cout << pa1[0].da1 << endl;
    cout << pa1[0].da2 << endl;
    cout << pa1[2].da1 << endl;
    cout << pa1[2].da2 << endl;

    delete pa1;
    cout << "helloword" << endl;
    system("pause");
    return 0;
}
