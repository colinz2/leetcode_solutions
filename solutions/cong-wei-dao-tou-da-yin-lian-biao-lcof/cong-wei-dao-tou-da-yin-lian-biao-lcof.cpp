// @Title: 从尾到头打印链表 LCOF
// @Author: colinjxc
// @Date: 2021-07-25T00:24:50+08:00
// @URL: https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    void recursion(ListNode*head, vector<int>& res){
        if (head==NULL) return;

        recursion(head->next, res);
        res.push_back(head->val);
    }
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        recursion(head, res);
        return res;
    }
};
