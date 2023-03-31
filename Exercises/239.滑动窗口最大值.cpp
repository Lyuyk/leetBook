/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int max=0;
        int sum=0;
        int length=nums.size();
        unordered_set<int> w;
        for(int i=0;i<length;i++)
        {
            max=(max>sum)?max:sum;
            if(i>k)
            {
                sum-=nums[i-k-1];
            }
            sum+=nums[i];
        }
        return max;
    }
};
// @lc code=end

