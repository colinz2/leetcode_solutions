// @Title: Linked List Cycle II
// @Author: colinjxc
// @Date: 2022-02-09T12:33:27+08:00
// @URL: https://leetcode-cn.com/problems/linked-list-cycle-ii


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    while (head) {
        if (head >= head->next) {
            return head->next;
        }
        head = head->next;
    }
    return NULL;
}
