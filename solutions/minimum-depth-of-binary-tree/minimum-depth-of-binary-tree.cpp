// @Title: Minimum Depth of Binary Tree
// @Author: colinjxc
// @Date: 2021-11-02T12:20:01+08:00
// @URL: https://leetcode-cn.com/problems/minimum-depth-of-binary-tree


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
    int minDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int min = 0;

        q.push({root, 1});
        while (root !=  nullptr && !q.empty()) {
            auto tp = q.front(); q.pop();
            auto node = tp.first;
            auto level = tp.second;
            if (node->left == nullptr && node->right == nullptr) {
                return level;
            }
            if (node->left != nullptr) q.push({node->left, level + 1});
            if (node->right != nullptr) q.push({node->right, level + 1});
        }

        return min;
    }
};
