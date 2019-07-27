#include<iostream>
using namespace std;
float *find(float p[][4], int m);
float *find2(float *p, int m);

int main()
{
	int test1[2][3] = { {1,2,3}, { 3,4,5} };
	int (*ppp)[3] = test1;
	cout << test1 << endl;
	cout << &test1 << endl;
	cout << test1[0][0] << endl;
	cout << &test1[0][0] << endl;
	cout <<*(*test1+1)<<"|"<<**(test1+1)<<"|"<< test1 + 1 << endl;

	cout << "PPP" << endl;
	cout << ppp << endl;
	cout << &ppp << endl;
	cout << ppp[0][0] << endl;
	cout << &ppp[0][0] << endl;
	cout << *(*ppp + 1) << endl;

	double th[3][3][3] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
	double(*pth)[3][3] = th;
	double ***ppth = (double ***)th;


	float *find1(float(*p)[4], int m);//查询序号为m的学生的四门课程的成绩
	float score[][4] = { { 50,51,52,55 },{ 70,70,40,80 },{ 77,99,88,67 } };//定义成绩数组，第一维可以为变量
	float *pf = NULL;//定义一个指针时一定要初始化
	//cout << sizeof(pf) << endl;
	int i, m;

	cout<<"请输入您想查询的学生的序号:";

	cin >> m;
	pf = find2((float*)score, m);//返回为一维数组指针，指向一个学生成绩
	//pf = find1(score, m);
	//pf = find(score, m);
	for (i = 0; i < 4; i++)
	{
		cout << *(pf + i) << " ";
		cout << pf[i] << "  ";
	}
	cout << endl;
	system("pause");
	return 0;
}
float *find1(float(*p)[4], int m)
{
	float *pf = NULL;
	pf = *(p + m);//p是指向二维数组的指针，加*取一维数组的指针
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
	/*for (int i = 0; i < 4; ++i)
	{
		cout << pf[i] << "  ";
		cout << *(pf + i) << endl;
	}*/
	return pf;
}
