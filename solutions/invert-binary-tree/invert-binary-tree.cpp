// @Title: Invert Binary Tree
// @Author: colinjxc
// @Date: 2022-03-04T00:07:55+08:00
// @URL: https://leetcode-cn.com/problems/invert-binary-tree


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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            std::swap(node->right, node->left);
            if (node->right) q.push(node->right);
            if (node->left) q.push(node->left);
        }
        return root;
    }
};
