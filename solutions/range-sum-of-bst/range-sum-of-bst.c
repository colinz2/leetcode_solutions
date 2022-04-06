// @Title: Range Sum of BST
// @Author: colinjxc
// @Date: 2022-02-05T03:07:09+08:00
// @URL: https://leetcode-cn.com/problems/range-sum-of-bst


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int rangeSumBST(struct TreeNode* root, int low, int high){
    if (root == NULL) return 0;
    if (root->val < low) {
        return rangeSumBST(root->right, low, high);
    } else if (root->val > high) {
        return rangeSumBST(root->left, low, high);
    }
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}
