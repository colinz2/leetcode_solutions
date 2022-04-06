// @Title: Construct String from Binary Tree
// @Author: colinjxc
// @Date: 2022-01-28T15:24:30+08:00
// @URL: https://leetcode-cn.com/problems/construct-string-from-binary-tree


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
    string tree2str(TreeNode* root) {
        string res;
        std::function<void(TreeNode*)> preorder = [&](TreeNode* node) {
            if (node == nullptr) return;
            res += std::to_string(node->val);
            if (node->left != nullptr || node->right != nullptr) {
                res += "(";
                preorder(node->left);
                res += ")";
            }
            if (node->right != nullptr ) {
                res += "(";
                preorder(node->right);
                res += ")";
            }
        };

        preorder(root);
        return res;
    }
};
