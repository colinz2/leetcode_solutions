// @Title: Maximum Depth of Binary Tree
// @Author: colinjxc
// @Date: 2022-02-06T14:41:11+08:00
// @URL: https://leetcode-cn.com/problems/maximum-depth-of-binary-tree


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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return std::max(maxDepth(root->right), maxDepth(root->left)) + 1;
    }
};
