// @Title: Split Linked List in Parts
// @Author: colinjxc
// @Date: 2022-02-03T20:59:39+08:00
// @URL: https://leetcode-cn.com/problems/split-linked-list-in-parts


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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k);
        if (head == nullptr) return res;
        int llen = 0;
        ListNode* curr = head;
        while (curr) {
            curr = curr->next;
            llen++;
        }
        
        ListNode* h = head;
        int plen = llen / k, rlen = llen % k;
        for (int i = 0; i < k; i++) {
            res[i] = h;
            for (int j = 1; j < plen +(i <rlen) && h; j++) {
                h = h->next;
            }
            if (h == nullptr) break;
            auto n = h->next;
            h->next = nullptr;
            h = n;
        }
        return res;
    }
};
