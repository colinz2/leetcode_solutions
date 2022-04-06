// @Title: 回文链表
// @Author: colinjxc
// @Date: 2022-02-05T01:29:30+08:00
// @URL: https://leetcode-cn.com/problems/aMhZSa


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
    bool isPalindrome(ListNode* head) {
        vector<ListNode*> vec;
        while (head) {
            vec.emplace_back(head);
            head = head->next;
        }

        for (int i = 0; i < vec.size()/2; i++) {
            if (vec[i]->val != vec[vec.size() - 1 -i]->val) {
                return false;
            }
        }
        return true;
    }
};
