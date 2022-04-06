// @Title: Sum Root to Leaf Numbers
// @Author: colinjxc
// @Date: 2022-02-06T22:19:47+08:00
// @URL: https://leetcode-cn.com/problems/sum-root-to-leaf-numbers


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void sumNumbersDfs(struct TreeNode* root, int sumPrev, int *total) {
    if (root == NULL) return;
    int num = sumPrev*10 + root->val;
    if (root->left == NULL && root->right == NULL) {
        *total += num;
        return;
    }
    if (root->left) sumNumbersDfs(root->left, num, total);
    if (root->right) sumNumbersDfs(root->right, num, total);
}

int sumNumbers(struct TreeNode* root){
    int sum = 0;
    sumNumbersDfs(root, 0, &sum);
    return sum;
}
