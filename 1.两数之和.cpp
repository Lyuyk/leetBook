class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        for(int i=0;i<nums.size(); i++)
        {
            auto iter= hashMap.find(target-nums[i]);
            if(iter!=hashMap.end())
            {
                return {i,iter->second};
            }
            hashMap[nums[i]]=i;
        }
        return {};
    }
};