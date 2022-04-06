// @Title: Rotate List
// @Author: colinjxc
// @Date: 2022-02-03T18:40:48+08:00
// @URL: https://leetcode-cn.com/problems/rotate-list


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if (head == NULL) return NULL;
    struct ListNode *last = head;
    int list_len = 1;
    while (last->next) {
        list_len++;
        last = last->next;
    }
    last->next = head;
    for (int i = 0; i < list_len - (k % list_len); i++) {
        last = last->next;
    }
    head = last->next;
    last->next = NULL;
    return head;
}
