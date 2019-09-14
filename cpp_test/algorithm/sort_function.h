#include <bits/stdc++.h>
using namespace std;
template <class T>
void s_swap(T *a, T *b)
{
    T temp;
    temp = *b;
    *b = *a;
    *a = temp;
}
template <class T>
void s_bubble(vector<T> &vec)
{
    for (size_t i = 1; i < vec.size(); i++)
    {
        for (size_t j = 0; j < vec.size() - i; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                s_swap(&vec[j], &vec[j + 1]);
            }
        }
    }
}
template <class T>
void s_selection(vector<T> &vec)
{
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        int min = i;
        for (size_t j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[min])
            {
                min = j;
            }
        }
        if (i != min)
            s_swap(&vec[min], &vec[i]);
    }
}
template <class T>
void s_insert(vector<T> &vec)
{
    for (size_t i = 1; i < vec.size(); i++)
    {
        T cur = vec[i];
        int j = i;
        while (j > 0 && vec[j - 1] > cur)
        {
            vec[j] = vec[j - 1];
            j--;
        }
        if (j != i)
            vec[j] = cur;
    }
}