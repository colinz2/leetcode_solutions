// @Title: Kth Smallest Element in a BST
// @Author: colinjxc
// @Date: 2022-01-30T20:22:41+08:00
// @URL: https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int kthSmallest(struct TreeNode* root, int k){
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
    size_t stack_index = 0;
    int val = 0;

    struct TreeNode* node = root;
    while (node != NULL || stack_index != 0) {
        while (node != NULL) {
            stack[stack_index++] = node;
            node = node->left;
        }
        // 是 --stack_index 不是 stack_index--
        node = stack[--stack_index];
        if (--k == 0) {
            val = node->val;
            break;
        }
        node = node->right;
    }

    free(stack);
    return val;
}
