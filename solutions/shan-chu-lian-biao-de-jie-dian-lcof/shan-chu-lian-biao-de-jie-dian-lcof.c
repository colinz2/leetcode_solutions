// @Title: 删除链表的节点 LCOF
// @Author: colinjxc
// @Date: 2022-02-05T01:19:17+08:00
// @URL: https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val){
    struct ListNode dummy = {.next = head};
    struct ListNode* prev = &dummy;
    while (head) {
        if (head->val == val) {
            prev->next = head->next;
            free(head);
            head = prev->next;
        } else {
            prev = head;
            head = head->next;
        }
    }
    return dummy.next;
}
