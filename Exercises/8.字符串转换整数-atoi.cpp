/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        bool sign = true;
        int i=0;
        while(i<s.size() && s[i]==' ')i++;

        if(s[i]=='-'){
            sign = false;
            i++;
        }
        else if(s[i]=='+')i++;

        if(s[i]<'0' || s[i]>'9')return 0;
        int res=0;
        int num;
        int border=__INT_MAX__/10;

        while(i<s.size()){
            if(s[i]<'0'||s[i]>'9')break;
            if(res>border||res==border&&s[i]>'7')
            return sign==true?__INT_MAX__:INT_MIN;

            num=s[i]-'0';
            res=res*10+num;
            i++;
        }
        return sign==true?res:-res;
    }
};
// @lc code=end

