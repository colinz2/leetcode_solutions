// @Title: Convert Sorted List to Binary Search Tree
// @Author: colinjxc
// @Date: 2022-02-03T00:11:23+08:00
// @URL: https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree


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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortListToBST(head, nullptr);
    }   

    TreeNode* sortListToBST(ListNode* head, ListNode* tail) {
        if (head == tail) {
            return nullptr;
        }
        ListNode* mid = head;
        ListNode* fast = head;
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            mid = mid->next;
        }
        TreeNode* node = new TreeNode(mid->val);
        node->left = sortListToBST(head, mid);
        node->right = sortListToBST(mid->next, tail);
        return node;
    }
};






