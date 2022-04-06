// @Title: Binary Tree Inorder Traversal
// @Author: colinjxc
// @Date: 2022-02-04T13:19:14+08:00
// @URL: https://leetcode-cn.com/problems/binary-tree-inorder-traversal


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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            auto node = st.top(); st.pop();
            res.emplace_back(node->val);
            root = node->right;
        }
        return res;
    }
};
