// @Title: Binary Tree Level Order Traversal
// @Author: realzhangm
// @Date: 2021-11-01T23:31:29+08:00
// @URL: https://leetcode-cn.com/problems/binary-tree-level-order-traversal


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root == nullptr) return res;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            res.push_back(vector<int>());
            for (int i = 0; i < levelSize; i++) {
                auto node = q.front(); q.pop();
                res.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};
