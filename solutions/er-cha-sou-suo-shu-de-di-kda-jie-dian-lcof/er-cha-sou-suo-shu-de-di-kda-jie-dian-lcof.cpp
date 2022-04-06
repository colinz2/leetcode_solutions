// @Title: 二叉搜索树的第k大节点  LCOF
// @Author: colinjxc
// @Date: 2022-02-15T20:27:59+08:00
// @URL: https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof


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
    int kthLargest(TreeNode* root, int k) {
        int res, cnt = 0;
        TreeNode* curr = root;
        stack<TreeNode*> stk;


        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->right;
            }
            curr = stk.top();
            if (++cnt == k) {
                res = curr->val;
                break;
            }
            stk.pop();
            curr = curr->left;
        }
        
        return res;
    }
};
