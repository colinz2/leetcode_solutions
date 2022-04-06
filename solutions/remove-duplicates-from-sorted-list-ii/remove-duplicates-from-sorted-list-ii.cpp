// @Title: Remove Duplicates from Sorted List II
// @Author: colinjxc
// @Date: 2018-12-20T23:44:10+08:00
// @URL: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii


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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy, *curr = head;

        while (curr) {
            ListNode* next = curr->next;
            if (next == NULL) break;
            if (curr->val == next->val) {
                while (next && curr->val == next->val) {
                    next = next->next;
                }
                pre->next = next;
                curr = next;
            } else {
                pre = curr;
                curr = next;
            }
        }
        return dummy.next;
    }
};
