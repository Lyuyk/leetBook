/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /*哈希表法*/
        // unordered_map<int, int> hashMap;
        // for(int i=0;i<numbers.size(); i++)
        // {
        //     auto iter= hashMap.find(target-numbers[i]);//查找键
        //     if(iter!=hashMap.end())
        //     {
        //         return {iter->second+1,i+1};//numbers[i+1]位置在后面
        //     }
        //     hashMap[numbers[i]]=i;//<值，位置>
        // }
        // return {-1,-1};

        /*二分法*/
        // for(int i=0;i<numbers.size();i++)
        // {
        //     int low=i+1;
        //     int high=numbers.size()-1;
        //     while(low<=high)
        //     {
        //         int mid=low+(high-low)/2;
        //         if(numbers[mid]==target-numbers[i])//找到
        //         {
        //                 return {i+1,mid+1};
        //         }
        //         else if(numbers[mid]>target-numbers[i])//在左边
        //         {
        //             high=mid-1;
        //         }
        //         else//在右边
        //         {
        //             low=mid+1;
        //         }
        //     }
        // }
        // return {-1,-1};

        /*双指针法*/
        int i=0;
        int j=numbers.size()-1;
        while (i<j)
        {
            if(numbers[i]+numbers[j]==target)
                return {i+1,j+1};
            else if(numbers[i]+numbers[j] > target)
            {
                j--;
            }
            else 
            {
                i++;
            }            
        }
        return {-1,-1};

        
    }
};
// @lc code=end

