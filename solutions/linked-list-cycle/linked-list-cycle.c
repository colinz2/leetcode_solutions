// @Title: Linked List Cycle
// @Author: colinjxc
// @Date: 2022-02-04T00:22:19+08:00
// @URL: https://leetcode-cn.com/problems/linked-list-cycle


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        head = head->next;
        if (head == fast) {
            return true;
        }
    } 
    return false;
}
