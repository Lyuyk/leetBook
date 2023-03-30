/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i= matrix.size()-1,j=0;//以左下角为flag
        while(i>=0&&j<matrix[0].size())
        {
            if(matrix[i][j]>target)i--;
            else if(matrix[i][j]<target)j++;
            else return true;
        }
        return false;
    }
};
// @lc code=end

