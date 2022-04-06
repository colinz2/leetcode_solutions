// @Title: 回文链表
// @Author: colinjxc
// @Date: 2022-02-05T01:37:54+08:00
// @URL: https://leetcode-cn.com/problems/aMhZSa


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    if (head == NULL) return false;
    if (head->next == NULL) return true;
    struct ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode* pre = NULL, *next = NULL;
    while (slow) {
        next = slow->next;
        slow->next = pre;
        pre = slow;
        slow = next;
    }

    while (pre && head) {
        if (pre->val != head->val) {
            return false;
        }
        pre = pre->next;
        head = head->next;
    }
    return true;
}
