/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i-1;j++)
            {
                int tmp = max(dp[j]*(i-j),j*(i-j));
                dp[i] = max(tmp, dp[i]);
            }
        }
        return dp[n];
    }
};
// @lc code=end

