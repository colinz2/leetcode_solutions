// @Title: Lowest Common Ancestor of a Binary Search Tree
// @Author: colinjxc
// @Date: 2022-02-01T04:50:36+08:00
// @URL: https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (root->val > std::max(p->val, q->val)) {
                root = root->left;
            } else if (root->val < std::min(p->val, q->val)) {
                root = root->right;
            } else {
                return root;
            }
        }
        return root;
    }
};
