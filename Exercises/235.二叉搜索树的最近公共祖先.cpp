/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val){// 保证 p->val < q->val
            TreeNode *tmp = p;
            p=q;
            q=tmp;
        }
        while(root)
        {
            if(root->val < p->val)//p,q 在 root 右子树
                root = root->right;//遍历至右子节点
            else if(root->val > q->val)//p,q 在 root 左子树
                root = root->left;//遍历至左子节点
            else break;
        }
        return root;
    }
};
// @lc code=end

