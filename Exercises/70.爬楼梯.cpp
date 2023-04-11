/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        long long a = 1, b = 1, sum;
        for(int i = 0;i < n; i++)
        {
            sum=a+b;
            a=b;
            b=sum;
        }
        return a;
    }
};
// @lc code=end

