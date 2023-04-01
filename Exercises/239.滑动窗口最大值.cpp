/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n= nums.size();
        if(n==0||k==0)return {};
        //滑动窗口左右
        int left = -k+1;//左右相差（k-1）
        int right = 0;

        deque<int> deq;//双端队列
        vector<int> res;

        while(right<n)
        {
            //判断上次循环左边是否是最大元素，是就pop掉，滑窗开始移动才需要判断
            if(left >= 1 && nums[left-1] == deq[0]) 
                deq.pop_front();

            while(!deq.empty() && deq[0] < nums[right])//小于nums[right]元素出队
                deq.pop_front();
            while(!deq.empty() && deq[deq.size()-1] < nums[right])//小于nums[right]元素出队,队头队尾检查一边保证单调递减，去掉该检查会导致如3,1情况下入2时，1不能及时出掉[1,3,1,2,0,5]
                deq.pop_back();
            
            deq.push_back(nums[right]);//right进队列

            if(left>=0) res.push_back(deq[0]);//滑窗形成
            left++;
            right++;
        }
        return res;        
    }
};
// @lc code=end

