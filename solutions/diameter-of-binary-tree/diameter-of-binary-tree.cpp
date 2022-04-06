// @Title: Diameter of Binary Tree
// @Author: colinjxc
// @Date: 2022-02-06T15:05:49+08:00
// @URL: https://leetcode-cn.com/problems/diameter-of-binary-tree


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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        depth(root, res);
        return res;
    }

    int depth(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        int d1 = depth(root->left, res);
        int d2 = depth(root->right, res);
        res = std::max(res, d1 + d2);
        return std::max(d1, d2) + 1;
    }
};
