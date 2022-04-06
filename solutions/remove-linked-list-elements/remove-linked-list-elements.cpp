// @Title: Remove Linked List Elements
// @Author: colinjxc
// @Date: 2018-10-22T22:15:15+08:00
// @URL: https://leetcode-cn.com/problems/remove-linked-list-elements


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr = head;
        ListNode *pre = NULL;
        while (curr) {
            if (curr->val == val) {
                if (pre != NULL)
                    pre->next = curr->next;
                else 
                    head = head->next;
            } else {
                pre = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};
