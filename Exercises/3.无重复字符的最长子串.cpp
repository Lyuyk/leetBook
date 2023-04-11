/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dic;//统计s[j]最后一次出现的索引
        int i=-1, res=0;
        for(int j=0;j<s.size();j++)
        {
            if(dic.find(s[j])!=dic.end())//若出现过s[j]
                i=max(i, dic[s[j]]);//更新左指针，若有重复字符在i，j间则更新i
            dic[s[j]]=j;//更新索引位置
            res=max(res,j-i);//保证取得最长的i，j区间
        }
        return res;
    }
};
// @lc code=end

