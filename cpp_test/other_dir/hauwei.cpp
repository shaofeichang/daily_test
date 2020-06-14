#include <bits/stdc++.h>
using namespace std;

bool isliangweishu(int num)
{
    return num / 100 == 0 && num / 10 != 0;
}
bool isyiweishu(int num)
{
    return num / 10 == 0 && num != 0;
}
bool isture(vector<int> vec)
{
    int si = vec.size();
    if (si % 2 == 0 && si > 0)
    {
        for (int i = 0; i < vec.size(); i += 2)
        {
            if (isliangweishu(vec[i]) && isyiweishu(vec[i + 1]))
            {
                si -= 2;
            }
        }
        if (si == 0)
        {
            return true;
        }
        si = vec.size();
        for (int i = 0; i < vec.size(); i += 2)
        {
            if (isyiweishu(vec[i]) && isliangweishu(vec[i + 1]))
            {
                si -= 2;
            }
        }
        if (si == 0)
        {
            return true;
        }
        return false;
    }
    if (isyiweishu(vec[0]) && isyiweishu(vec[vec.size() - 1]))
    {
        for (int i = 1; i < vec.size() - 1; i++)
        {
            if (isyiweishu(vec[i]))
            {
                return false;
            }
        }
    }
    if (isliangweishu(vec[0]) && isliangweishu(vec[vec.size() - 1]))
    {
        for (int i = 1; i < vec.size() - 1; i++)
        {
            if (isliangweishu(vec[i]))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    string s;
    vector<string> str;
    while (getline(cin, s))
    {
        vector<int> v;
        int pos = 0, pos1 = 0;
        while (pos != s.npos)
        {
            pos = s.find(" ", pos1);
            if (pos != s.npos)
            {
                v.push_back(stoi(s.substr(pos1, pos - pos1)));
                pos1 = pos + 1;
            }
            else
                v.push_back(stoi(s.substr(pos1, s.length() - pos1)));
        }
        if (isture(v))
            str.push_back("true");
        else
            str.push_back("false");
    }
    for (size_t i = 0; i < str.size() - 1; i++)
    {
        cout << str[i] << ' ';
    }
    cout << str.back();
    
    getchar();
    return 0;
    /*vector<int> vec;
    while (true)
    {
        int num = 0;
        char ch;
        vec.clear();
        bool res = false;
        while (true)
        {
            cin >> num;
            ch = getchar();
            if (ch == '\n')
                vec.push_back(num);
        }

        if (isture(vec))
            cout << "true" << ' ';
        else
            cout << "false" << ' ';
    }*/
}