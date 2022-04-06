// @Title: Delete the Middle Node of a Linked List
// @Author: colinjxc
// @Date: 2022-02-04T00:33:06+08:00
// @URL: https://leetcode-cn.com/problems/delete-the-middle-node-of-a-linked-list


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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode *fast = head->next, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return head;
    }
};
