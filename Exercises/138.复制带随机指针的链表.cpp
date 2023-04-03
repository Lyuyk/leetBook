/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)return nullptr;
        Node* cur= head;
        //复制各自节点，构建拼接链表
        while(cur!=nullptr)
        {
            Node* tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
        //构建各自新节点的random指向
        cur = head;
        while(cur!=nullptr)
        {
            if(cur->random != nullptr)
            {
                cur->next->random= cur->random->next;
            }
            cur= cur->next->next;
        }
        //拆分链表
        cur= head->next;
        Node* pre = head, *res = head->next;
        while(cur->next != nullptr)
        {
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = nullptr;
        return res;
    }
};
// @lc code=end

