// @Title: Average of Levels in Binary Tree
// @Author: realzhangm
// @Date: 2021-11-02T00:47:37+08:00
// @URL: https://leetcode-cn.com/problems/average-of-levels-in-binary-tree


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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            double sum = 0.0;
            for (int i =  0; i < levelSize; i++) {
                auto node = q.front(); q.pop();
                sum += (double)node->val; 
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(sum / levelSize);
        }

        return res;
    }
};
