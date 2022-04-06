// @Title: Remove Nth Node From End of List
// @Author: colinjxc
// @Date: 2022-02-01T17:45:51+08:00
// @URL: https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* fast = head;
    struct ListNode dummy = {.next = head};
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    struct ListNode* pre = &dummy;
    while (fast) {
        fast = fast->next;
        pre = head;
        head = head->next;
    }
    pre->next = head->next;
    free(head);
    return dummy.next;
}
