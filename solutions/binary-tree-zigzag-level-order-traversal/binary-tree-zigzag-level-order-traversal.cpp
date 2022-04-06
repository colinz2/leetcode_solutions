// @Title: Binary Tree Zigzag Level Order Traversal
// @Author: colinjxc
// @Date: 2022-02-17T00:33:06+08:00
// @URL: https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);

        vector<int> tmp;
        int cnt = 0;
        while (q.size() > 0) {
            tmp.clear();
            auto len = q.size();
            for (int i = 0; i < len; i++) {
                auto node = q.front();
                q.pop();
                if (node) {
                    tmp.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (tmp.size() > 0) {
                if (++cnt % 2 == 0) reverse(tmp.begin(), tmp.end());
                res.emplace_back(tmp);
            }
        }

        return res;
    }
};
