/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    unordered_map<int, int> map;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int pre_root, 
    int inorder_left,int inorder_right){
        if(inorder_left > inorder_right)
            return NULL;
        TreeNode* root = new TreeNode(preorder[pre_root]);
        
        // 根节点在中序序列中位置，划分左右子树边界
        int inorder_root = map[preorder[pre_root]];
        // 左子树前序中根节点的位置在，pre_root+1，左子树在中序中边界，[inorder_left,inorder_root-1]
        root->left = build(preorder,inorder,pre_root+1,inorder_left,inorder_root-1);
        // 右子树在前序中的根节点位于：根节点+左子树长度+1 即 pre_root+inorder_root-inorder_left+1
        // 右子树在中序中的边界：[inorder_root+1,inorder_right]
        root->right = build(preorder,inorder,pre_root+inorder_root-inorder_left+1,inorder_root+1,inorder_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 中序序列用于查找根节点
        for(int i=0;i< inorder.size();i++)
        {
            map[inorder[i]] = i;
        }
        return build(preorder,inorder,0,0,inorder.size()-1);
    }
};
// @lc code=end

