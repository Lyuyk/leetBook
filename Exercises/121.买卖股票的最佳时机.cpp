/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = __INT_MAX__, profit=0;
        for(int price: prices)
        {
            cost = min(cost, price);
            profit = max(profit,price - cost);
        }
        return profit;
    }
};
// @lc code=end

