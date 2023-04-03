/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> tnQueue;
        vector<vector<int>> res;
        if(root!=nullptr)tnQueue.push(root);
        while(!tnQueue.empty())
        {
            vector<int> tmp;
            for(int i= tnQueue.size();i>0;i--)
            {
                TreeNode* node = tnQueue.front();
                tnQueue.pop();
                tmp.push_back(node->val);
                if(node->left)tnQueue.push(node->left);
                if(node->right)tnQueue.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end

