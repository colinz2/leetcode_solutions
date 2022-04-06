// @Title: Convert Binary Number in a Linked List to Integer
// @Author: colinjxc
// @Date: 2022-02-05T04:02:40+08:00
// @URL: https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    int res = 0;
    while (head) {
        res = (res << 1) + head->val;
        head = head->next;
    }
    return res;
}
