// @Title: Delete Node in a Linked List
// @Author: colinjxc
// @Date: 2021-07-06T22:28:01+08:00
// @URL: https://leetcode-cn.com/problems/delete-node-in-a-linked-list


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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
