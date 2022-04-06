// @Title: Second Minimum Node In a Binary Tree
// @Author: colinjxc
// @Date: 2022-01-30T15:22:21+08:00
// @URL: https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree


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
    int findSecondMinimumValue(TreeNode* root) {
        int second = -1;
        std::function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == nullptr) {
                return;
            }
            if (second != -1 && second <= node->val) {
                return;
            }
            if (node->val > root->val) {
                second = node->val;
            }

            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        return second;
    }
};

