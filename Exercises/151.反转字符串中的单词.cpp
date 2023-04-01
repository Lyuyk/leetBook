/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string res;
        string subStr;
        while(getline(ss,subStr,' '))
        {
            if(!subStr.empty())
                res = subStr + ' ' + res;
        }

        res.pop_back();//去掉最开始后面的空格 subStr+' '+""
        return res;
    }
};
// @lc code=end

