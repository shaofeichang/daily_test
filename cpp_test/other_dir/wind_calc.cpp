#include <cmath>
#include <iostream>
using namespace std;
// 风速计算，1.计算在射面时 车体方位；2.根据车体方向角 计算风速分速度； 3.计算相对车体的风速分速度
void windCalculate(double x, double y, double Vb, double Cw, double windVelocity, double windDierction, double &LongitudinalWind, double &CrossWind)
{
    double fw = atan2(x, y);
    double Wind_x = -Vb * sin(Cw) + windVelocity * sin(windDierction);
    double Wind_y = -Vb * cos(Cw) + windVelocity * cos(windDierction);
    double dandao_x = sin(fw);
    double dandao_y = cos(fw);
    LongitudinalWind = Wind_x * dandao_x + Wind_y * dandao_y;
    CrossWind = Wind_x * dandao_y - Wind_y * dandao_x;
}

int main()
{
    double x = 10;
    double y = 10;
    double Vb = 5;
    double Cw = 30 * 3.1415926 / 180;
    double windVelocity = 10;
    double windDierction = 30 * 3.1415926 / 180;
    double LongitudinalWind;
    double CrossWind;
    windCalculate(x, y, Vb, Cw, windVelocity, windDierction, LongitudinalWind, CrossWind);
    cout << LongitudinalWind << "  " << CrossWind << endl;
    system("pause");
    return 0;
}