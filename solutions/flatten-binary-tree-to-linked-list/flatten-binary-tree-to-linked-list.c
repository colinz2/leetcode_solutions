// @Title: Flatten Binary Tree to Linked List
// @Author: colinjxc
// @Date: 2022-01-30T21:38:08+08:00
// @URL: https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten_recur(struct TreeNode* root, struct TreeNode** last) {
    if (root == NULL) {
        return;
    }
    flatten_recur(root->right, last);
    flatten_recur(root->left, last);
    root->right = *last;
    root->left = NULL;
    *last = root;
}

void flatten(struct TreeNode* root){
    struct TreeNode* last = NULL;
    flatten_recur(root, &last);
}
