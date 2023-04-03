/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode *preHead=new ListNode(0);
        preHead->next=head;
        ListNode *pre=preHead;
        ListNode *cur=head;
        while(cur)
        {
            while(cur->next && cur->val==cur->next->val)
            {
                cur=cur->next;//跳过当前重复节点
            }
            if(pre->next==cur)
            {
                pre=pre->next;//pre无重复节点，pre后移
            }
            else
            {//pre不移动，指向已经遍历完的链表结尾
                pre->next=cur->next;
            }
            cur = cur->next;
        }
        return preHead->next;
    }
};
// @lc code=end

