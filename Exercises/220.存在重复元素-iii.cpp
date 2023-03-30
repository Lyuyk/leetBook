/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
public:
    int getID(int x, long w)
    {
        return x < 0 ? (x+1ll) / w-1:x/w;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<int, int> map;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            long x= nums[i];
            int id= getID(x,valueDiff+1ll);
            if(map.count(id))
            {
                return true;
            }
            if(map.count(id-1)&&abs(x-map[id-1])<=valueDiff)
            {
                return true;
            }
            if(map.count(id+1)&&abs(x-map[id+1])<=valueDiff)
            {
                return true;
            }
            map[id]=x;
            if(i>=indexDiff)
            {
                map.erase(getID(nums[i-indexDiff],valueDiff+1ll));
            }
        }
        return false;
        
    }
};
// @lc code=end

