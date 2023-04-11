/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            nums[i] += max(nums[i-1],0);//dp 两种情况
            res = max(res, nums[i]);
        }
        return res;
    }
};
// @lc code=end

