// @Title: 二叉搜索树中两个节点之和
// @Author: colinjxc
// @Date: 2022-03-05T22:35:44+08:00
// @URL: https://leetcode-cn.com/problems/opLdQZ


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
    bool findTarget(TreeNode* root, int k) {
        vector<int> res;
        inorder(root, res);

        int lo = 0, hi = res.size() - 1;
        while (lo < hi) {
            int sum = res[lo] + res[hi];
            if (sum > k) {
                hi--;
            } else if (sum < k) {
                lo++;
            } else return true;
        }
        return false;
    }

    void inorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

};
