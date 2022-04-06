// @Title: Swap Nodes in Pairs
// @Author: colinjxc
// @Date: 2018-12-11T16:54:53+08:00
// @URL: https://leetcode-cn.com/problems/swap-nodes-in-pairs


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode dummy(0);
        dummy.next = head;

        ListNode* pre = &dummy;
        ListNode* curr = pre->next;
        while (curr) {
            ListNode* next = curr->next;
            if (next) {
                pre->next = next;
                curr->next = next->next;
                next->next = curr;

                pre = curr;
                curr = curr->next;
            } else {
                break;
            }
        }
        return dummy.next;
    }
};
