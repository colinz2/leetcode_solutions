// @Title: Search in a Binary Search Tree
// @Author: colinjxc
// @Date: 2022-01-27T17:15:14+08:00
// @URL: https://leetcode-cn.com/problems/search-in-a-binary-search-tree


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
    TreeNode* searchBST(TreeNode* root, int val) {
        queue<TreeNode*> _q;
        _q.push(root);

        TreeNode* node = nullptr;
        while (!_q.empty()) {
            node = _q.front();
            _q.pop();
            if (node == nullptr || node->val == val) {
                return node;
            } else if (node->val < val) {
                _q.push(node->right);
            } else {
                _q.push(node->left);
            }
        }

        return nullptr;
    }
};
