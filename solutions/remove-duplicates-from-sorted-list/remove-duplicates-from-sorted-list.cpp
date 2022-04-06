// @Title: Remove Duplicates from Sorted List
// @Author: colinjxc
// @Date: 2018-12-07T00:22:49+08:00
// @URL: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list


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
        ListNode* curr = head;
        while (curr) {
            if (curr->next == nullptr) break;

            if (curr->val == curr->next->val) {
                ListNode* d = curr->next;
                curr->next = curr->next->next;
                delete d;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};
