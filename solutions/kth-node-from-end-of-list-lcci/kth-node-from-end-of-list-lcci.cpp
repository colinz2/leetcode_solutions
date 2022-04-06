// @Title: Kth Node From End of List LCCI
// @Author: colinjxc
// @Date: 2022-02-04T14:07:25+08:00
// @URL: https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci


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
    int kthToLast(ListNode* head, int k) {
        ListNode* n1 = head, *n2 = head;
        int i = 0;
        for (; i < k && n1 != nullptr; i++) {
            n1 = n1->next;
        }
        if (n1 == nullptr && i < k) {
            return -1;
        }
        while (n1) {
            n1 = n1->next;
            n2 = n2->next;
        }
        return n2->val;
    }
};
