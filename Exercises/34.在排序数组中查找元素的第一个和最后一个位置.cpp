/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {searchLeftOrRightBound(nums,target,"left"),searchLeftOrRightBound(nums,target,"right")};
    }
private:
    int searchLeftOrRightBound(vector<int>& nums, int target, const string& bound)
    {
        int left = 0, right = nums.size() - 1;
        int res = -1;
        while(left <= right){
            int mid = (left + right) >> 1;
            if(nums[mid] < target){
                left = mid+1;
            }
            else if(nums[mid]>target){
                right = mid-1;
            }
            else{
                res = mid;
                if(bound == "left"){
                    right = mid - 1;
                }
                else if(bound == "right"){
                    left = mid + 1;
                }
                else{

                }
            }
        }
        return res;
    }
};
// @lc code=end

