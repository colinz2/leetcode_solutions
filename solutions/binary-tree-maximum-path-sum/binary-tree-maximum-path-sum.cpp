// @Title: Binary Tree Maximum Path Sum
// @Author: colinjxc
// @Date: 2022-02-06T20:29:55+08:00
// @URL: https://leetcode-cn.com/problems/binary-tree-maximum-path-sum


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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        calculateSum(root, res);
        return res;
    }

    int calculateSum(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        int s1 = calculateSum(root->left, res);
        int s2 = calculateSum(root->right, res);
        s1 = max(0, s1);
        s2 = max(0, s2);
        res = max(res, s1 + s2 + root->val);
        return max(s1, s2) + root->val;
    }
};
