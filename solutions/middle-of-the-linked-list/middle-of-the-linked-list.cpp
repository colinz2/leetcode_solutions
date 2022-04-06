// @Title: Middle of the Linked List
// @Author: colinjxc
// @Date: 2018-12-11T17:03:20+08:00
// @URL: https://leetcode-cn.com/problems/middle-of-the-linked-list


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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL) {
            if (fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            } else {
                fast = NULL;
            }
        }
        return slow;
    }
};
