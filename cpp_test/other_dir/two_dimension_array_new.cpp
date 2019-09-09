#include <bits/stdc++.h>
using namespace std;
// 内存不连续
void unknowTwo(int row, int col)
{
    int **arrayPtr = NULL;
    arrayPtr = new int *[row];
    for (size_t i = 0; i < row; i++)
    {
        arrayPtr[i] = new int[col];
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arrayPtr[i][j] = (i + 1) * (j + 1);
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << std::setw(10) << arrayPtr[i][j] << "  ";
        }
        cout << endl;
    }
    for (size_t i = 0; i < row; i++)
    {
        delete[] arrayPtr[i];
    }
}

void unknowTwoSeries(int row, int col)
{
    int *arrayPtr;
    arrayPtr = new int[col * row];

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arrayPtr[i + j] = (i + 1) * (j + 1);
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << std::setw(10) << arrayPtr[i + j] << "  ";
        }
        cout << endl;
    }

    delete[] arrayPtr;
}
// 内存连续
void knowCol(int row)
{
    const int col = 6;
    int(*arrayPtr)[col];
    arrayPtr = new int[row][col];
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arrayPtr[i][j] = (i + 1) * (j + 1);
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << std::setw(10) << arrayPtr[i][j] << "  ";
        }
        cout << endl;
    }
    delete[] arrayPtr;
}

// 内存不连续
void knowRowUnSeries(int col)
{
    const int row = 3;
    int *arrayPtr[row];
    for (size_t i = 0; i < row; i++)
    {
        arrayPtr[i] = new int[col];
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arrayPtr[i][j] = (i + 1) * (j + 1);
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << std::setw(10) << &arrayPtr[i][j] << "  ";
        }
        cout << endl;
    }
    for (size_t i = 0; i < row; i++)
    {
        delete[] arrayPtr[i];
    }
}

// 内存连续
void knowRowSerise(int col)
{
    const int row = 3;
    int *arrayPtr[row];
    arrayPtr[0] = new int[col * row];
    for (int i = 1; i < row; i++)
    {
        arrayPtr[i] = arrayPtr[i - 1] + col;
    }

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arrayPtr[i][j] = (i + 1) * (j + 1);
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << std::setw(10) << &arrayPtr[i][j] << "  ";
        }
        cout << endl;
    }

    delete[] arrayPtr[0];
}

// c-style malloc

void Cunknow(int row, int col)
{
    int **a = NULL;
    a = (int **)malloc(row * sizeof(int *));
    for (size_t i = 0; i < row; i++)
    {
        a[i] = (int *)malloc(col * sizeof(int));
    }

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            a[i][j] = (i + 1) * (j + 1);
        }
    }

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << setw(10) << &a[i][j] << " ";
        }
        cout << endl;
    }
    for (size_t i = 0; i < row; i++)
    {
        free(a[i]);
    }
    free(a);
}

void CknowCol(int col)
{
    const int row = 3;
    int(*a)[row] = (int(*)[row])malloc(sizeof(int *) * col);
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            a[i][j] = (i + 1) * (j + 100);
        }
    }

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << setw(10) << a[i][j] << " ";
        }
        cout << endl;
    }
    free(a);
}

void CknowColSerial(int col)
{
    const int row = 3;
    int *a[row];
    a[0] = (int *)malloc(sizeof(int) * col * row);
    for (size_t i = 1; i < row; i++)
    {
        a[i] = a[i - 1] + col;
    }
    free(a[0]);
}

int main()
{
    Cunknow(3, 6);
    cout << endl;
    cout << "know col" << endl;
    CknowCol(6);
    cout << endl;
    cout << "know col serial" << endl;
    CknowColSerial(6);
    cout << endl;
    /*
    unknowTwoSeries(3, 6);
    cout << endl;
    unknowTwo(3, 6);
    cout << endl;
    knowCol(3);
    cout << endl;
    knowRowUnSeries(6);
    cout << endl;
    knowRowSerise(6);
    cout << endl;
    */

    system("pause");
    return 0;
}