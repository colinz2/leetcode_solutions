// @Title: Recover Binary Search Tree
// @Author: colinjxc
// @Date: 2022-03-01T22:38:06+08:00
// @URL: https://leetcode-cn.com/problems/recover-binary-search-tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *prev;
struct TreeNode *first;
struct TreeNode *last;

void inorder(struct TreeNode* root) {
    if (root == NULL) {
        return root;
    }
    inorder(root->left);
    if (prev != NULL) {
        if (prev->val > root->val) {
            if (first == NULL) {
                first = prev;
            }
            last = root;
        }
    }
    prev = root;
    inorder(root->right);
}

void recoverTree(struct TreeNode* root){
    if (root == NULL) {
        return;
    }
    prev = NULL, first = NULL, last = NULL;
    inorder(root);
    if (first != NULL && last != NULL) {
        int val = first->val;
        first->val = last->val;
        last->val = val;
    }
}

