#include <iostream>
using namespace std;
float *find(float p[][4], int m);
float *find1(float (*p)[4], int m);
float *find2(float *p, int m);

int main()
{
    int test1[2][3] = {{1, 2, 3}, {3, 4, 5}};
    int(*ppp)[3] = test1;
    cout << " test1: " << test1 << "\t &test1: " << &test1 << "test1[0][0]: " << test1[0][0] << endl;
    cout << *(*test1 + 1) << "|" << **(test1 + 1) << "|" << test1 + 1 << endl;
    cout << "PPP: " << ppp << " &ppp " << &ppp << " " << ppp[0][0] << " " << &ppp[0][0] << " " << *(*ppp + 1) << endl;

    double th[3][3][3] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
    double(*pth)[3][3] = th;
    double ***ppth = (double ***)th;

    float score[][4] = {{50, 51, 52, 55}, {70, 70, 40, 80}, {77, 99, 88, 67}};
    float *pf = NULL;
    cout << "sizeof(pf) = : " << sizeof(pf) << endl;
    int i, m;

    cout << "input a number 0<num<4:";
    cin >> m;

    // pf = find2((float *)score, m); //返回为一维数组指针，指向一个学生成绩
    pf = find1(score, m);
    //pf = find(score, m);
    for (i = 0; i < 4; i++)
    {
        cout << *(pf + i) << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
float *find1(float (*p)[4], int m)
{
    float *pf = NULL;
    pf = *(p + m); //p是指向二维数组的指针，加*取一维数组的指针
    return pf;
}
float *find(float p[][4], int m)
{
    float *pf = NULL;
    pf = *(p + m);
    return pf;
}
float *find2(float *p, int m)
{
    float *pf = NULL;
    pf = p + 4 * m;
    return pf;
}
