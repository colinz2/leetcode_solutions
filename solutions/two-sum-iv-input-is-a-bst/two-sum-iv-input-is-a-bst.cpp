// @Title: Two Sum IV - Input is a BST
// @Author: colinjxc
// @Date: 2018-12-19T20:37:26+08:00
// @URL: https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return preorderFind(root, k, seen);
    }
    
    bool preorderFind(TreeNode* root, int k, unordered_set<int>& seen) {
        if (root == NULL) {
            return false;
        }
        if (seen.find(k - root->val) != seen.end()) {
            return true;
        }
        seen.insert(root->val);
        return preorderFind(root->left, k, seen) || preorderFind(root->right, k, seen);
    }
};
