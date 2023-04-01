/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())return {};
        vector<int> res;
        int left=0;//左边界
        int right=matrix[0].size()-1;//右边界
        int top=0;//上边界
        int bottom=matrix.size()-1;//下边界

        while (true)
        {
            //left->right
            for(int i=left;i<=right;i++)
            {
                res.push_back(matrix[top][i]);
            }
            if(++top>bottom)break;
            
            //top->botton
            for(int i=top;i<=bottom;i++)
            {
                res.push_back(matrix[i][right]);
            }
            if(--right<left)break;

            //right->left
            for(int i=right;i>=left;i--)
            {
                res.push_back(matrix[bottom][i]);
            }
            if(--bottom<top)break;

            for(int i=bottom;i>=top;i--)
            {
                res.push_back(matrix[i][left]);
            }
            if(++left>right)break;
        }
        return res;
    }
};
// @lc code=end

