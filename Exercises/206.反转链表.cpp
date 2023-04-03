/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        return recur(head, nullptr);
    }
private:
    ListNode* recur(ListNode* cur, ListNode* pre){
        if(cur==nullptr)return pre;//终止条件
        ListNode* res = recur(cur->next, cur);//后继节点递归
        cur->next = pre;//修改节点引用指向
        return res;//返回反转链表的头节点
    }

};
// @lc code=end

