// @Title: Lowest Common Ancestor of a Binary Tree
// @Author: colinjxc
// @Date: 2022-02-09T23:45:27+08:00
// @URL: https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree


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
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        auto l = lowestCommonAncestor(root->left, p, q);
        auto r = lowestCommonAncestor(root->right, p, q);
        if (l == nullptr && r == nullptr) 
            return nullptr;
        else if (l == nullptr) 
            return r;
        else if (r == nullptr) 
            return l;
        return root;
    }
};
