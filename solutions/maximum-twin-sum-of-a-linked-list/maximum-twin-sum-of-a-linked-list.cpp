// @Title: Maximum Twin Sum of a Linked List
// @Author: colinjxc
// @Date: 2022-02-05T23:27:14+08:00
// @URL: https://leetcode-cn.com/problems/maximum-twin-sum-of-a-linked-list


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
    int pairSum(ListNode* head) {
        vector<int> vec;
        for (auto p = head; p; p = p->next) {
            vec.push_back(p->val);
        }
        int sum = 0;
        for (int i = 0; i < vec.size()/2; i++) {
            sum = std::max(sum, vec[i] + vec[vec.size()-1-i]);
        }
        return sum;
    }
};
