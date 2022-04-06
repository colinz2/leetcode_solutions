// @Title: Linked List Cycle LCCI
// @Author: colinjxc
// @Date: 2022-02-04T01:03:19+08:00
// @URL: https://leetcode-cn.com/problems/linked-list-cycle-lcci


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
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> listSet;
        while (head) {
            if (listSet.count(head) != 0) {
                return head;
            }
            listSet.insert(head);
            head = head->next; 
        }
        return nullptr;
    }
};
