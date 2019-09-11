#include <bits/stdc++.h>
using namespace std;

void dfs(vector<string> &ans, string &begin, string &end);

vector<vector<string>> res;
unordered_map<string, vector<string>> Hash;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> dirc(wordList.begin(), wordList.end());
    if (dirc.find(endWord) == dirc.end())
        return res;
    unordered_set<string> beginw{beginWord};
    unordered_set<string> endw{endWord};
    int flag1 = 0, flag2 = 0; //第一个是否找到最短序列标志, 第二个是否反转标志。

    while (!beginw.empty())
    {
        unordered_set<string> tmp;
        for (auto str : beginw)
            dirc.erase(str);
        for (auto str : beginw)
        {
            for (int i = 0; i < str.size(); ++i)
            {
                string s = str;
                for (char j = 'a'; j <= 'z'; ++j)
                {
                    s[i] = j;
                    if (dirc.find(s) == dirc.end())
                        continue;
                    if (endw.find(s) != endw.end())
                        flag1 = 1;
                    else
                        tmp.insert(s);
                    flag2 ? Hash[s].push_back(str) : Hash[str].push_back(s);
                }
            }
        }
        if (flag1)
            break; //已经找到最短序列退出循环。
        if (tmp.size() <= endw.size())
            beginw = tmp;
        else
        {
            beginw = endw;
            endw = tmp;
            flag2 = !flag2; //这里需要使用！反转。
        }
    }
    vector<string> ans = {beginWord};
    dfs(ans, beginWord, endWord);
    return res;
}

void dfs(vector<string> &ans, string &begin, string &end)
{
    if (begin == end)
    {
        res.emplace_back(ans);
        return;
    }
    if (Hash.find(begin) == Hash.end())
        return;
    for (auto str : Hash[begin])
    {
        ans.emplace_back(str);
        dfs(ans, str, end);
        ans.pop_back();
    }
}
int main()
{
    string str1 = "hit";
    string str2 = "cog";
    vector<string> strlist = {"hot","dot","dog","lot","log","cog"};
    findLadders(str1, str2, strlist);
}