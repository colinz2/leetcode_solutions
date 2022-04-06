// @Title: Reverse Linked List
// @Author: colinjxc
// @Date: 2022-02-01T14:45:23+08:00
// @URL: https://leetcode-cn.com/problems/reverse-linked-list


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* new_head = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}
