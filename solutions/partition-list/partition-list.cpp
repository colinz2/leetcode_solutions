// @Title: Partition List
// @Author: colinjxc
// @Date: 2022-02-03T20:51:22+08:00
// @URL: https://leetcode-cn.com/problems/partition-list


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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return nullptr;
        ListNode gHead, dummy;
        dummy.next = head;
        ListNode *curr = &dummy, *g = &gHead;
        while (curr->next) {
            if (curr->next->val >= x) {
                g->next = curr->next;
                curr->next = curr->next->next;
                g = g->next;
            } else {
                curr = curr->next;
            }
        }
        g->next = nullptr;
        curr->next = gHead.next;
        return dummy.next;
    }
};
