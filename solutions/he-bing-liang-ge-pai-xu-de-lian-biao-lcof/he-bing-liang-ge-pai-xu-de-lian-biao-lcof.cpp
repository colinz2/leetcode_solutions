// @Title: 合并两个排序的链表  LCOF
// @Author: colinjxc
// @Date: 2022-02-04T13:44:09+08:00
// @URL: https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* l3 = &dummy;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                l3->next = l2;
                l2 = l2->next;
            } else {
                l3->next = l1;
                l1 = l1->next;
            }
            l3 = l3->next;
        }
        if (l1) {
            l3->next = l1;
        } else if (l2) {
            l3->next = l2;
        }
        return dummy.next;
    }
};
