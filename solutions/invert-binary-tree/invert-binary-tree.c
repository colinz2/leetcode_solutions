// @Title: Invert Binary Tree
// @Author: colinjxc
// @Date: 2022-02-06T15:10:15+08:00
// @URL: https://leetcode-cn.com/problems/invert-binary-tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL) return root;
    invertTree(root->left);
    invertTree(root->right);
    struct TreeNode* tmp;
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    return root;
}
