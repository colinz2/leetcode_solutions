// @Title: Kth Smallest Element in a BST
// @Author: colinjxc
// @Date: 2022-01-30T20:26:32+08:00
// @URL: https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst


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
    int kthSmallest(TreeNode* root, int k) {
        std::vector<TreeNode*> stack;
        while (root || !stack.empty()) {
            while (root) {
                stack.push_back(root);
                root = root->left;
            }
            root = stack.back();
            stack.pop_back();
            if (--k == 0) {
                return root->val;
            }
            root = root->right;
        }
        return -1;
    }
};
