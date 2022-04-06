// @Title: Validate Binary Search Tree
// @Author: colinjxc
// @Date: 2018-12-13T16:10:43+08:00
// @URL: https://leetcode-cn.com/problems/validate-binary-search-tree


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
    //中序遍历，从小到大排列
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorderVisit(root, v);
        for (int i = 1; i < v.size(); i++) {
            if (v[i - 1] >= v[i]) {
                return false;
            }
        }
        return true;
    }

    void inorderVisit(TreeNode* root, vector<int>& v) {
        if (root) {
            inorderVisit(root->left, v);
            v.push_back(root->val);
            inorderVisit(root->right, v);
        }
    }
};
