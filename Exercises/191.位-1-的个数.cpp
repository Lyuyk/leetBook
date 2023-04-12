/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while(n!=0)
        {
            n&=(n-1);//每次运算都会消去n最末尾的一个1
            res++;
        }
        return res;
    }
};
// @lc code=end

