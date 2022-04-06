// @Title: Sum Lists LCCI
// @Author: colinjxc
// @Date: 2022-02-03T23:30:22+08:00
// @URL: https://leetcode-cn.com/problems/sum-lists-lcci


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add = 0, val1 = 0, val2 = 0;
        ListNode dummy;
        ListNode* l3 = &dummy;
        while (l1 || l2 || add) {
            val1 = 0, val2 = 0;
            if (l1) {
                val1 = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val2 = l2->val;
                l2 = l2->next;
            }

            add += val1 + val2;
            l3->next = new ListNode(add %10), l3 = l3->next;
            add /= 10;
        }
        return dummy.next;
    }
};
