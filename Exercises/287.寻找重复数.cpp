/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int r=nums[0];
        while(nums[r]!=r)
        {
            swap(nums[0],nums[r]);
            r=nums[0];
        }
        return r;
    }
};
// @lc code=end

