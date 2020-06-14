#include <cmath>
#include <cstdlib>
class targetTrace
{
public:
	targetTrace();																		 //Ĭ�ϳ�ʼ�����캯��������ֱ���˶�
	targetTrace(double t, double noise[], double start[], double vec[3]);				 //��ʼ�����캯��.����ֱ��
	targetTrace(double t, double noise[], double start[], double vec[3], double acc[3]); //��ʼ�����캯�����ȼ���
	double *getCurrentPos();															 //��ȡĿ�굱ǰʱ�̹۲�ֵ���ⲿ����
	void targetGenerate();																 //Ŀ�꺽·����
private:
	double PI;
	double startPos[3];
	double startVec[3];
	double startAcc[3];
	double currentPos[3];
	double currD_GD_FW[3];
	double T;
	int timeCount;
	double Noise[3];
	bool CAFlag;
};

targetTrace::targetTrace()
{
	T = 0.02;
	PI = 3.1415926;
	startPos[0] = 5000;
	startPos[1] = 100;
	startPos[2] = 5000;
	startVec[0] = -50;
	startVec[1] = 0;
	startVec[2] = -20;
	startAcc[0] = 0;
	startAcc[1] = 0;
	startAcc[2] = 0;
	Noise[0] = 1;
	Noise[1] = 0.5;
	Noise[2] = 0.5;
	timeCount = 0;
	CAFlag = false;
}
targetTrace::targetTrace(double t, double noise[], double start[], double vec[3])
{
	T = t;
	for (int i = 0; i < 3; i++)
	{
		startPos[i] = start[i];
		startVec[i] = vec[i];
		Noise[i] = noise[i];
	}
	PI = 3.1415926;
	timeCount = 0;
	CAFlag = false;
}
targetTrace::targetTrace(double t, double noise[], double start[], double vec[3], double acc[3])
{
	T = t;
	for (int i = 0; i < 3; i++)
	{
		startPos[i] = start[i];
		startVec[i] = vec[i];
		startAcc[i] = acc[i];
		Noise[i] = noise[i];
	}
	PI = 3.1415926;
	timeCount = 0;
	CAFlag = true;
}
void targetTrace::targetGenerate()
{
	double vec[3], acc[3];
	for (int i = 0; i < 3; i++)
	{
		acc[i] = startAcc[i];
		vec[i] = startVec[i] + acc[i] * T * timeCount;

		if (CAFlag)
			currentPos[i] = startPos[i] + vec[i] * T * timeCount + acc[i] * pow(timeCount * T, 2) / 2;
		else
			currentPos[i] = startPos[i] + vec[i] * T * timeCount;
	}
	timeCount++;
}
double *targetTrace::getCurrentPos()
{
	// double D = sqrt(currentPos[0] * currentPos[0] + currentPos[1] * currentPos[1] + currentPos[2] * currentPos[2]);
	// double fwj = 6000 * asin(currentPos[1] / sqrt(D * D - currentPos[2] * currentPos[2])) / (2 * PI);
	// double gdj = 6000 * asin(currentPos[2] / D) / (2 * PI);
	// currD_GD_FW[0] = D + rand() % int(2 * Noise[0] + 1) + Noise[0];
	// currD_GD_FW[1] = gdj + rand() % int(2 * Noise[1] + 1) + Noise[1];
	// currD_GD_FW[2] = fwj + rand() % int(2 * Noise[2] + 1) + Noise[2];
	// return currD_GD_FW;
	return currentPos;
}
