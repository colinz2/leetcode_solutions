// @Title: Linked List Cycle II
// @Author: colinjxc
// @Date: 2022-02-09T12:23:19+08:00
// @URL: https://leetcode-cn.com/problems/linked-list-cycle-ii


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
    ListNode *detectCycle(ListNode *head) {
        ListNode *f = head, *s = head;
        while (f && f->next) {
            f = f->next->next;
            s = s->next;
            if (f == s) {
                while (head != s) {
                    head = head->next;
                    s = s->next;
                }
                return head;
            }
        }
        return nullptr;
    }
};
