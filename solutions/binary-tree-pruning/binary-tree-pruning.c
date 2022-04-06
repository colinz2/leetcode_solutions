// @Title: Binary Tree Pruning
// @Author: colinjxc
// @Date: 2022-03-01T21:29:29+08:00
// @URL: https://leetcode-cn.com/problems/binary-tree-pruning


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* pruneTree(struct TreeNode* root){
    if (root == NULL) {
        return NULL;
    }
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (!root->left && !root->right && !root->val) {
        return NULL;
    }

    return root;
}
