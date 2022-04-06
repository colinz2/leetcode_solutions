// @Title: Binary Tree Pruning
// @Author: colinjxc
// @Date: 2022-03-01T21:26:56+08:00
// @URL: https://leetcode-cn.com/problems/binary-tree-pruning


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
    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        root->right = pruneTree(root->right);
        root->left = pruneTree(root->left);
        if (!root->right && !root->left && !root->val) {
            return nullptr;
        }
        return root;
    }
};
