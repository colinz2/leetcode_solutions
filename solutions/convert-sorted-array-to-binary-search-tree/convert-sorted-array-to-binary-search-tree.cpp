// @Title: Convert Sorted Array to Binary Search Tree
// @Author: colinjxc
// @Date: 2022-02-01T22:00:39+08:00
// @URL: https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree


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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }

    TreeNode* dfs(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        int m = (l+r)/2;
        auto node = new TreeNode(nums[m]);
        node->right = dfs(nums, m+1, r);
        node->left = dfs(nums, l, m-1);
        return node;
    }
};
