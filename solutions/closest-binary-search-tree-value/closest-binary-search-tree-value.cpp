// @Title: Closest Binary Search Tree Value
// @Author: colinjxc
// @Date: 2022-01-27T18:56:51+08:00
// @URL: https://leetcode-cn.com/problems/closest-binary-search-tree-value


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
    int closestValue(TreeNode* root, double target) {
        int closest = INT_MAX;
        auto getClose = [](int a, int b, double target) ->int {
            double d1 = static_cast<double>(a) - target;
            double d2 = static_cast<double>(b) - target;
            if (std::abs(d1) > std::abs(d2)) {
                return b;
            }
            return a;
        };

        std::function<void(TreeNode*)> search = [&](TreeNode* node) {
            if (node == nullptr) return;
            closest = getClose(closest, node->val, target);
            if (node->left == nullptr) {
                return search(node->right);
            } else if (node->right == nullptr) {
                return search(node->left);
            }
            search(node->left);
            search(node->right);
        };
        search(root);
        return closest;
    }
};
