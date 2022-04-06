// @Title: Reverse Linked List II
// @Author: colinjxc
// @Date: 2022-02-03T18:10:31+08:00
// @URL: https://leetcode-cn.com/problems/reverse-linked-list-ii


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode dummy = {.next = head};
    struct ListNode *curr = head, *pre = &dummy, *next;
    int index = 0;
    while (curr) {
        if (++index >= left && index < right) {
            next = curr->next;
            curr->next = next->next;
            next->next = pre->next;
            pre->next = next;
        } else {
            pre = curr;
            curr = curr->next;
        }
    }
    return dummy.next;
}
