// @Title: 链表中倒数第k个节点 LCOF
// @Author: colinjxc
// @Date: 2022-03-01T09:35:36+08:00
// @URL: https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof


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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < k && fast; i++) {
            fast = fast->next;
        }
        while (fast && slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};
