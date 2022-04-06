// @Title: Flatten Binary Tree to Linked List
// @Author: colinjxc
// @Date: 2022-01-30T21:03:33+08:00
// @URL: https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list


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
    void flatten(TreeNode* root) {
        std::vector<TreeNode*> vec;
        std::function<void(TreeNode*)> f1 = [&](TreeNode* node) {
            if (node == nullptr) {
                return;
            }
            vec.push_back(node);
            f1(node->left);
            f1(node->right);
        };
        f1(root);

        for (int i = 1; i < vec.size(); i++) {
            vec[i]->left = nullptr;
            vec[i]->right = nullptr;
            vec[i-1]->left = nullptr;
            vec[i-1]->right = vec[i];
        }
    }
};
