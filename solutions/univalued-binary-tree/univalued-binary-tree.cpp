// @Title: Univalued Binary Tree
// @Author: colinjxc
// @Date: 2022-03-01T17:56:46+08:00
// @URL: https://leetcode-cn.com/problems/univalued-binary-tree


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
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        std::stack<TreeNode*> stk;
        int target = root->val;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->val != target) {
                return false;
            }
            root = root->right;
        }
        return true;
    }
};
