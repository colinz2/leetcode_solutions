// @Title: Diameter of Binary Tree
// @Author: colinjxc
// @Date: 2022-02-06T14:51:54+08:00
// @URL: https://leetcode-cn.com/problems/diameter-of-binary-tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int a, int b) {
    return a > b ? a : b;
}

int depthOfBinaryTree(struct TreeNode* root, int *diameter) {
    if (root == NULL) return 0;
    int dleft = depthOfBinaryTree(root->left, diameter);
    int dright = depthOfBinaryTree(root->right, diameter);
    *diameter = max(*diameter, dleft + dright);
    return max(dleft, dright) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    int diameter = 0;
    depthOfBinaryTree(root, &diameter);
    return diameter;
}
