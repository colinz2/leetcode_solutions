// @Title: Convert BST to Greater Tree
// @Author: colinjxc
// @Date: 2022-02-14T20:25:05+08:00
// @URL: https://leetcode-cn.com/problems/convert-bst-to-greater-tree


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
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return nullptr;
        root->val += addTree(root->right, 0);
        convertBST(root->left);
        convertBST(root->right);
        addLeft(root->left, root->val);
        return root;
    }

    void addLeft(TreeNode* root, int val) {
        if (root == nullptr) return;
        root->val += val;
        addLeft(root->left, val);
        addLeft(root->right, val);
    }

    int addTree(TreeNode *root, int rootVal) {
        if (root == nullptr) return 0;
        return addTree(root->left, 0) + addTree(root->right, 0) + root->val + rootVal;
    }


};
