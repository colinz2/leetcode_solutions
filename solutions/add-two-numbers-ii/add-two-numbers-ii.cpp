// @Title: Add Two Numbers II
// @Author: colinjxc
// @Date: 2022-02-09T17:15:48+08:00
// @URL: https://leetcode-cn.com/problems/add-two-numbers-ii


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
        stack<int> s1, s2;

        while (l1) s1.push(l1->val), l1 = l1->next;
        while (l2) s2.push(l2->val), l2 = l2->next;
        
        int add = 0;
        while (!s1.empty() || !s2.empty() || add) {
            if (!s1.empty()) {
                add += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                add += s2.top();
                s2.pop();
            }
            ListNode* node = new ListNode(add % 10, dummy.next);
            dummy.next = node;
            add = add / 10;
        }
        return dummy.next;
    }
};
