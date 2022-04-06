// @Title: Same Tree
// @Author: colinjxc
// @Date: 2022-01-29T03:29:40+08:00
// @URL: https://leetcode-cn.com/problems/same-tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q ==  NULL) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
