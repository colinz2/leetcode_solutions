// @Title: Odd Even Linked List
// @Author: colinjxc
// @Date: 2022-02-03T02:09:50+08:00
// @URL: https://leetcode-cn.com/problems/odd-even-linked-list


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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* odd = head;
        ListNode* evenHead = odd->next;
        ListNode* even = evenHead;
        while (even != nullptr && even->next != nullptr) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            even = even->next;
            odd = odd->next;
        }
        odd->next = evenHead;
        return head;
    }
};
