// @Title: Symmetric Tree
// @Author: colinjxc
// @Date: 2018-10-19T22:08:17+08:00
// @URL: https://leetcode-cn.com/problems/symmetric-tree


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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return  issym(root->left, root->right);
    }
    
private:
    bool issym(TreeNode* l, TreeNode* r) {
        if (l == NULL && r == NULL) {
            return true;
        }
        
        if (l == NULL || r == NULL) {
            return false;
        }
        
        if (l->val == r->val) {
            return issym(l->left, r->right) && issym(l->right, r->left);
        } else {
            return false;
        }

    }
};
