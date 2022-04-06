// @Title: Lowest Common Ancestor of a Binary Search Tree
// @Author: colinjxc
// @Date: 2022-02-01T04:34:06+08:00
// @URL: https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;    
}
