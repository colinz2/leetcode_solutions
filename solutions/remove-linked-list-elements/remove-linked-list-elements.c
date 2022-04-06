// @Title: Remove Linked List Elements
// @Author: colinjxc
// @Date: 2018-10-18T00:02:36+08:00
// @URL: https://leetcode-cn.com/problems/remove-linked-list-elements


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode **list = &head;
    while (*list != NULL) {
        if ((*list)->val == val) {
            *list = (*list)->next;
        } else {
            list = &(*list)->next;
        }
    }
    return head;
}
