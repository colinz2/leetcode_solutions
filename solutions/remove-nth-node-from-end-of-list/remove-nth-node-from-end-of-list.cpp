// @Title: Remove Nth Node From End of List
// @Author: colinjxc
// @Date: 2022-01-29T13:55:55+08:00
// @URL: https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode dummy;
        dummy.next = head;

        for (int i = 0; i < n; i++) {
            if (fast == nullptr) 
                return nullptr;
            fast = fast->next; 
        }
        ListNode* pre = &dummy;
        while (fast) {
            fast = fast->next;
            pre = head;
            head = head->next;
        }
        pre->next = head->next;
        delete head;

        return dummy.next;
    }
};
