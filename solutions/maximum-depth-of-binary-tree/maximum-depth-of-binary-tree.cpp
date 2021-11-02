// @Title: Maximum Depth of Binary Tree
// @Author: realzhangm
// @Date: 2021-11-02T12:25:16+08:00
// @URL: https://leetcode-cn.com/problems/maximum-depth-of-binary-tree


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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto level_size = q.size();
            for (auto i = 0; i < level_size; i++) {
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            depth++;
        }

        return depth;
    }
};
