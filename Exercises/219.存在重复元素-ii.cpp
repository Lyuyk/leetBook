/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> w;
        int length=nums.size();
        for(int i=0;i<length;i++)
        {
            if(i>k)
            {
                w.erase(nums[i-k-1]);
            }
            if(w.count(nums[i]))
            {
                return true;
            }
            w.emplace(nums[i]);//加入新的元素
        }
        return false;
    }
};
// @lc code=end

