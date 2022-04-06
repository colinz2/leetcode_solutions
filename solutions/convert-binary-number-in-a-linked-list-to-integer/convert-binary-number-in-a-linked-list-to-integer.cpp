// @Title: Convert Binary Number in a Linked List to Integer
// @Author: colinjxc
// @Date: 2022-02-05T03:58:45+08:00
// @URL: https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer


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
    int getDecimalValue(ListNode* head) {
        if (head == nullptr) return 0;
        ListNode *prev = nullptr, *next = nullptr;        
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        int res = 0;
        for (int i = 0; prev; prev = prev->next, i++) {
            res += prev->val << i;
        }
        return res;
    }
};
