/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */

// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1;//数位
        long start = 1;//开始数字
        long count = 9;
        while(n>count){
            n -= count;
            digit += 1;
            start *= 10;
            count = digit*start*9;
        }
        long num = start + (n-1)/digit;//第二步
        return to_string(num)[(n-1)%digit]-'0';
    }
};
// @lc code=end

