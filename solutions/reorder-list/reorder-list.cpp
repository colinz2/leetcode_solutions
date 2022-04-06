// @Title: Reorder List
// @Author: colinjxc
// @Date: 2022-02-05T01:08:43+08:00
// @URL: https://leetcode-cn.com/problems/reorder-list


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
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        vector<ListNode*> vec;
        while (head) {
            vec.push_back(head);
            head = head->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i++]->next = vec[j];
            if (i == j) break;
            vec[j--]->next = vec[i];
        }
        //这一步不能忘啊。
        vec[i]->next = nullptr;
    }
};
