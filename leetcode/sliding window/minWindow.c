/*
   76. 最小覆盖子串
   给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。
   示例：
   输入: S = "ADOBECODEBANC", T = "ABC"
   输出: "BANC"
   说明：
   如果 S 中不存这样的子串，则返回空字符串 ""。
   如果 S 中存在这样的子串，我们保证它是唯一的答案。
*/
#define LEN  125
char* minWindow(char* s, char* t)
{
    int hash[LEN] = {0};
    int start=0, end=0, tLen=strlen(t), sLen=strlen(s);
    int minStart=0, minLen = INT_MAX;
    for(int i = 0; t[i]; i++) 
        hash[t[i]]++;	//统计 t 串字母出现的次数
    while(end < sLen) {
    	//若 s 串有 t 串的字母，则对应的哈希表减一，tlen 也减一
        if(hash[s[end]]-- > 0) 
            tLen--; 
        end++; //窗口继续滑动
        while(tLen == 0) {//当匹配到一个有效的子串
            if(end-start < minLen) {//更新最小串
                minStart=start;
                minLen=end-start;
            }
            hash[s[start]]++;//开始缩小窗口
            //若 s[start] 在 t 串中，则 tlen 要++,说明缩小之后，当前窗口不存在有效的子串了
            if(hash[s[start]] > 0)
                tLen++; 
            start++; //接着移动
        }
    }
    if(minLen != INT_MAX) {
        s[minStart+minLen] = '\0';
        return s+minStart;
    }
    return "";
}