// @Title: Binary Tree Level Order Traversal
// @Author: colinjxc
// @Date: 2022-01-26T13:20:19+08:00
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
        queue<TreeNode*> _q;
        _q.push(root);

        vector<int> tmp;
        while (!_q.empty()) {
            int n = _q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = _q.front();
                _q.pop();
                if (node == nullptr) continue;
                tmp.push_back(node->val);
                _q.push(node->left);
                _q.push(node->right);
            }
            if (tmp.size() > 0) {
                res.push_back(tmp);
                tmp.clear();
            }
        }
        return res;
    }
};
