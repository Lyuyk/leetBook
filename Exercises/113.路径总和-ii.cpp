/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> res;
    vector<int> path;
    void recur(TreeNode *root, int target){
        if(root==nullptr)return;
        path.push_back(root->val);
        target-= root->val;
        if(target==0 && root->left==nullptr && root->right==nullptr){
            res.push_back(path);
        }
        recur(root->left, target);
        recur(root->right, target);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        recur(root, targetSum);
        return res;
    }
};
// @lc code=end

