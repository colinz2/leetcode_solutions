// @Title: Linked List Random Node
// @Author: colinjxc
// @Date: 2022-02-04T01:46:23+08:00
// @URL: https://leetcode-cn.com/problems/linked-list-random-node


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
    Solution(ListNode* head) {
        while (head) {
            vec_.push_back(head);
            head = head->next;
        }
    }
    
    int getRandom() {
        return vec_[rand() % vec_.size()]->val;
    }
private:
    std::vector<ListNode*> vec_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
