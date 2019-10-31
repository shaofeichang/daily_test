#include <bits/stdc++.h>
using namespace std;

int main()
{
    double num;
    cin >> num;
    if (num <= 3000)
        printf("%.2f\n", 0);
    if (num > 3000 && num <= 5000)
    {
        double temp = (num - 3000) * 0.05;
        printf("%.2f\n", temp);

    }
    if (num > 5000 && num <= 20000)
    {
        double temp = (num - 5000) * 0.1 + 2000*0.05;
        printf("%.2f\n", temp);

    }
    if (num > 20000)
    {
        double temp = (num - 20000) * 0.15 + 15000 * 0.1 + 2000*0.05;
        printf("%.2f\n", temp);

    }
    // system("pause");
    // return 0;
    // string name[] = {"小明", "小红", "小白", "小新", "小李", "小张"};
    // string code[] = {"001", "002", "003", "004", "005", "006"};
    // string str;
    // cin >> str;
    // cout<<name[stoi(str)-1]<<endl;
    // int x, y, z;
    // cin >> x >> y >> z;
    // if (x == z || y == z || x + y == z)
    //     cout << "true" << endl;
    // else
    //     cout << "false" << endl;
    system("pause");
    return 0;
}