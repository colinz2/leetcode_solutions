// @Title: Minimum Height Tree LCCI
// @Author: colinjxc
// @Date: 2022-03-05T23:44:43+08:00
// @URL: https://leetcode-cn.com/problems/minimum-height-tree-lcci


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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0, nums.size(), nums);
    }

    TreeNode* helper(int left, int right, vector<int>& nums) {
        if (left >= right) return nullptr; 
        int mid = (left + right) >> 1;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = helper(left, mid, nums);
        node->right = helper(mid+1, right, nums);

        return node;
    }
};
