// @Title: 反转链表 LCOF
// @Author: colinjxc
// @Date: 2021-07-08T23:27:10+08:00
// @URL: https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof


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
    ListNode* reverseList(ListNode* head) {
        ListNode* newNode = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = newNode;
            newNode = head;
            head = next;
        }
        return newNode;
    }
};
