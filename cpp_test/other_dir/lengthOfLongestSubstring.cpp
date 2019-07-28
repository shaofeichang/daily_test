#include <string>
#include <iostream>
using namespace std;
int lengthOfLongestSubstring1(string s)
{
    int m[256] = {0}; //字符有256个
    int left = 0;     //查找的左边界
    int mlen = 0;     //结果
    for (int i = 0; i < s.length(); i++)
    {
        if (m[s[i]] == 0 || m[s[i]] < left)
        {
            mlen = max(mlen, i - left + 1);
        }
        else
        {
            left = m[s[i]];
        }
        m[s[i]] = i + 1;
    }
    return mlen;
}

int lengthOfLongestSubstring2(string s)
{
    int len = 0;     //存放结果
    int start = 0;   //存放起始查找位置
    string str = ""; //存放无重复字符子串
    for (int i = 0; i < s.length(); i++)
    {
        if (str.find(s[i]) == -1) //未找到重复字符，放入str
            str = str + s[i];
        else //找到重复子串
        {
            len = len > str.length() ? len : str.length(); //更改最大字串长度
            i = s.find_first_of(s[i], start);              //从第start位置开始找s[i]
            start = i + 1;                                 //下一次查找开始的位置
            str = "";                                      //还原str
        }
    }
    len = len > str.length() ? len : str.length();
    return len;
}
int main()
{
    string str = "stringstring";
    cout<<lengthOfLongestSubstring2(str)<<endl;
    cout<<lengthOfLongestSubstring1(str)<<endl;
    system("pause");
    return 0;
}