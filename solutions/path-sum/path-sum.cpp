// @Title: Path Sum
// @Author: colinjxc
// @Date: 2022-01-31T03:14:15+08:00
// @URL: https://leetcode-cn.com/problems/path-sum


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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        } 
        if (!root->left  && !root->right) {
            return targetSum == root->val;
        }
        int nextSum = targetSum - root->val;
        return hasPathSum(root->left, nextSum) || hasPathSum(root->right, nextSum);
    }
};
