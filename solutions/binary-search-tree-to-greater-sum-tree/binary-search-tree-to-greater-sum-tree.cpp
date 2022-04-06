// @Title: Binary Search Tree to Greater Sum Tree
// @Author: colinjxc
// @Date: 2022-02-14T20:56:59+08:00
// @URL: https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree


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
    TreeNode* bstToGst(TreeNode* root) {
        std::stack<TreeNode*> stk;
        TreeNode* curr = root;
        int sum = 0;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->right;
            }
            curr = stk.top(), stk.pop();
            sum += curr->val;
            curr->val = sum;
            curr = curr->left;
        }
        return root;
    }
};
