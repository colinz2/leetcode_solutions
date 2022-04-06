// @Title: Merge In Between Linked Lists
// @Author: colinjxc
// @Date: 2022-02-05T23:49:04+08:00
// @URL: https://leetcode-cn.com/problems/merge-in-between-linked-lists


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode *ap = list1, *bp = list1;
    struct ListNode* head = list1;
    for (int i = 0; list1; list1 = list1->next, i++) {
        if (i == a - 1) ap = list1;
        if (i == b + 1) bp = list1;
    }
    ap->next = list2;
    for (; list2->next; list2 = list2->next);
    list2->next = bp;
    return head;
}
