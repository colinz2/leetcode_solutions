// @Title: Reorder List
// @Author: colinjxc
// @Date: 2022-02-05T22:22:30+08:00
// @URL: https://leetcode-cn.com/problems/reorder-list


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


void reorderList(struct ListNode* head){
    // 1 分一半
    // 2 逆序
    // 3 合并
    if (head == NULL || head->next == NULL) return head;
    // 1
    struct ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode *l2 = slow->next, *l1 = head;
    slow->next = NULL;
    // 2
    struct ListNode *prev = NULL, *next = NULL;
    while (l2) {
        next = l2->next;
        l2->next = prev;
        prev = l2;
        l2 = next;
    }
    l2 = prev;
    // 3
    while (l1 && l2) {
        struct ListNode* l1next = l1->next;
        struct ListNode* l2next = l2->next;

        l2->next = l1next;
        l1->next = l2;
        l1 = l1next;
        l2 = l2next;
    }
    return head;
}
