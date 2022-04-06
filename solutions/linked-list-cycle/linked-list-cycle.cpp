// @Title: Linked List Cycle
// @Author: colinjxc
// @Date: 2022-02-01T02:40:12+08:00
// @URL: https://leetcode-cn.com/problems/linked-list-cycle


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
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        while (fast && head) {
            head = head->next;
            if (fast->next)
                fast = fast->next->next;
            else
                break;
            if (head == fast) return true;
        }
        return false;
    }
};
