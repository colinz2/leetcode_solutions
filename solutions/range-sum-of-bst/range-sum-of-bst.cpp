// @Title: Range Sum of BST
// @Author: colinjxc
// @Date: 2022-02-05T03:02:31+08:00
// @URL: https://leetcode-cn.com/problems/range-sum-of-bst


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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        dfs(root, low, high, res);
        return res;
    }

    void dfs(TreeNode* root, int low, int high, int& res) {
        if (root == nullptr) return;
        if (root->val >= low && root->val <= high) {
            res += root->val;
            dfs(root->left, low, high, res);
            dfs(root->right, low, high, res);
        } else if (root->val < low) {
            dfs(root->right, low, high, res);
        } else {
            dfs(root->left, low, high, res);
        }
    }
};
