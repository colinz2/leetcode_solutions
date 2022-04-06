// @Title: Odd Even Linked List
// @Author: colinjxc
// @Date: 2022-02-03T11:38:56+08:00
// @URL: https://leetcode-cn.com/problems/odd-even-linked-list


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if (head == NULL) return NULL;
    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* evenHead = even;
    while (even != NULL && even->next != NULL) {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
