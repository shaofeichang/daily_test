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
template <typename T>
void s_shell(vector<T> &vec)
{
    int gap = 1;
    while (gap < vec.size())
        gap = gap * 3 + 1;
    while (gap > 0)
    {
        for (int i = gap; i < vec.size(); i++)
        {
            int temp = vec[i];
            int j = i - gap;
            while (j >= 0 && vec[j] > temp)
            {
                vec[j + gap] = vec[j];
                j -= gap;
            }
            vec[j + gap] = temp;
        }
        gap = (int)(gap / 3);
    }
}
template <typename T>
vector<T> sub_merge(vector<T> vecl, vector<T> vecr)
{
    int i = 0;
    vector<T> result;
    while (vecl.size() > 0 && vecr.size() > 0)
    {
        if (vecl[0] <= vecr[0])
        {
            result.push_back(vecl[0]);
            vecl.erase(vecl.begin());
        }
        else
        {
            result.push_back(vecr[0]);
            vecr.erase(vecr.begin());
        }
    }
    while (vecl.size() > 0)
    {
        result.push_back(vecl[0]);
        vecl.erase(vecl.begin());
    }
    while (vecr.size() > 0)
    {
        result.push_back(vecr[0]);
        vecr.erase(vecr.begin());
    }
    return result;
}
template <typename T>
vector<T> sort_merge(vector<T> vec)
{
    if (vec.size() < 2)
        return vec;
    int middle = vec.size() / 2;
    vector<T> left(vec.begin(), vec.begin() + middle);
    vector<T> right(vec.begin() + middle, vec.end());
    return sub_merge(sort_merge(left), sort_merge(right));
}
template <typename T>
void s_merge(vector<T> &vec)
{
    vec = sort_merge(vec);
}
template <typename T>
int partition(vector<T> &vec, int left, int right)
{
    int pivot = left;
    int index = pivot + 1;
    for (size_t i = index; i <= right; i++)
    {
        if(vec[i] < vec[pivot])
        {
            s_swap(&vec[i], &vec[index]);
            index ++;
        }
    }
    s_swap(&vec[pivot], &vec[index - 1]);
    return index - 1;
}
template <typename T>
vector<T> sort_quick(vector<T> &vec, int left, int right)
{
    if(left < right)
    {
        int index = partition(vec, left, right);
        sort_quick(vec, left, index - 1);
        sort_quick(vec, index + 1, right);
    }
    return vec;
}

template <typename T>
void s_quick(vector<T> &vec)
{
    sort_quick(vec, 0, vec.size() - 1);
}