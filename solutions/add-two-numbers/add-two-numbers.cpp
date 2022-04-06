// @Title: Add Two Numbers
// @Author: colinjxc
// @Date: 2022-02-09T16:59:30+08:00
// @URL: https://leetcode-cn.com/problems/add-two-numbers


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* l3 = &dummy;
        int add = 0;
        while (l1 || l2 || add) {
            if (l1) {
                add += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                add += l2->val;
                l2 = l2->next;
            }
            l3->next = new ListNode(add % 10);
            l3 = l3->next;
            add = add / 10; 
        }
        return dummy.next;
    }
};
