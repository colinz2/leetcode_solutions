// @Title: Reverse Linked List II
// @Author: colinjxc
// @Date: 2022-01-28T00:02:14+08:00
// @URL: https://leetcode-cn.com/problems/reverse-linked-list-ii


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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;

        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }
        ListNode *curr = pre->next;
        for (int i = left; i < right; ++i) {
            ListNode *t = curr->next;
            curr->next = t->next;
            t->next = pre->next;
            pre->next = t;
        }
        return dummy->next;
    }
};
