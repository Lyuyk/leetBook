/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        //层序遍历
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        while(!node_queue.empty()){
            root=node_queue.front();
            if(root){
                ans+=to_string(root->val);
                node_queue.push(root->left);
                node_queue.push(root->right);
            }else ans+="null";
            ans.push_back(',');
            node_queue.pop();
        }
        cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="null,")
            return nullptr;
        string tep_string;
        TreeNode dummyHeadNode,*dummyHead=&dummyHeadNode;
        queue<TreeNode**> node_queue;
        node_queue.push(&(dummyHead->left));
        for(char ch:data){
            if(ch==','){
                TreeNode** cur_node_pointer=node_queue.front();
                node_queue.pop();
                if(tep_string=="null")
                    *cur_node_pointer=nullptr;
                else{
                    *cur_node_pointer=new TreeNode(stoi(tep_string));
                    node_queue.push(&((*cur_node_pointer)->left));
                    node_queue.push(&((*cur_node_pointer)->right));
                }
                tep_string.clear();
            }else tep_string.push_back(ch);
        }
        return dummyHead->left;
    }

    
};



// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

