// @Title: Rotate List
// @Author: colinjxc
// @Date: 2022-02-03T19:29:11+08:00
// @URL: https://leetcode-cn.com/problems/rotate-list


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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode* last = head;
        int list_len = 1;
        for (; last->next; list_len++, last = last->next );
        last->next = head;

        for (int i = 0; i < list_len - (k % list_len); i++) {
            last = last->next;
        }
        head = last->next;
        last->next = nullptr;
        return head;
    }
};
