// @Title: Path Sum
// @Author: colinjxc
// @Date: 2022-02-06T20:36:36+08:00
// @URL: https://leetcode-cn.com/problems/path-sum


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int targetSum){
    if (root == NULL) return false;
    if (!root->right && !root->left && root->val == targetSum) return true;
    int val = targetSum - root->val;
    return hasPathSum(root->left, val) || hasPathSum(root->right, val);
}
