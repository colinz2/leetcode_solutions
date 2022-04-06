// @Title: Plus One Linked List
// @Author: colinjxc
// @Date: 2022-02-04T01:25:15+08:00
// @URL: https://leetcode-cn.com/problems/plus-one-linked-list


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
    ListNode* plusOne(ListNode* head) {
        std::stack<ListNode*> stack;
        ListNode* head2 = head;
        while (head) {
            stack.push(head);
            head = head->next;
        }
        int add = 1;
        while (!stack.empty()) {
            int tmp = stack.top()->val + add; 
            add = tmp / 10;
            stack.top()->val = tmp % 10;
            stack.pop();
        }
        if (add) {
            auto newHead = new ListNode(add, head2);
            return newHead;
        }

        return head2;
    }
};
