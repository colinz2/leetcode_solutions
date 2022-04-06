// @Title: 删除链表的倒数第 n 个结点
// @Author: colinjxc
// @Date: 2022-02-05T18:51:09+08:00
// @URL: https://leetcode-cn.com/problems/SLwz0R


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;
        ListNode dummy(-1, head);
        ListNode *fast = head, *slow = &dummy;
        for (int i = 0; i < n && fast != nullptr; i++) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        auto next = slow->next->next;
        delete slow->next;
        slow->next = next;

        return dummy.next;
    }
};
