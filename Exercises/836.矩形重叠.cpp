/*
 * @lc app=leetcode.cn id=836 lang=cpp
 *
 * [836] 矩形重叠
 */

// @lc code=start
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[0]==rec1[2]||rec1[1]==rec1[3]||rec2[0]==rec2[2]||rec2[1]==rec2[3]){
            return false;
        }

        return !(rec1[2]<=rec2[0]||     //1右在2左的左边（左）
                 rec1[3]<=rec2[1]||     //1上在2下的下边（下）
                 rec1[0]>=rec2[2]||     //1左在2右的右边（右）
                 rec1[1]>=rec2[3]);     //1下在2上的上边（上）
    }
};
// @lc code=end

