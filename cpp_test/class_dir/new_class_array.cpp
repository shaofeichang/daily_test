#include <iostream>
using namespace std;

class A
{
public:
    A() {}
    A(int num) : num(num)
    {
        switch (num)
        {
        case 1:
            this->l = num + 100;
            this->r = num + 100;
            this->u = num + 100;
            this->d = num + 100;
            break;
        case 2:
            this->l = num + 1000;
            this->r = num + 1000;
            this->u = num + 1000;
            this->d = num + 1000;
            break;
        case 3:
            this->l = num + 10000;
            this->r = num + 10000;
            this->u = num + 10000;
            this->d = num + 10000;
            break;
        default:
            break;
        }
    }
    void setNum(int n)
    {
        this->num = n;
        this->l = n + 1;
        this->r = n + 2;
        this->u = n + 3;
        this->d = n + 4;
    }
    int getNum()
    {
        cout << "lrud : " << l << " " << r << " " << u << " " << d << endl;
        return this->num;
    }

private:
    int num;
    int l, r, u, d;
};

int main()
{
    A **Aptr = NULL;
    int row = 3;
    int col = 6;
    Aptr = new A *[row];
    for (size_t i = 0; i < row; i++)
    {
        Aptr[i] = new A[col];
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            A a(i + 1);
            Aptr[i][j] = a;
            //Aptr[i][j].setNum((i + 1) * (j + 1));
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << Aptr[i][j].getNum() << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}