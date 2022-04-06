// @Title: Convert Sorted Array to Binary Search Tree
// @Author: colinjxc
// @Date: 2022-02-01T22:51:15+08:00
// @URL: https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        def build(nums:List[int], l:int, r:int) -> TreeNode:
            if l > r:
                return None
            m = (l+r)>>1
            return TreeNode(nums[m], build(nums, l, m-1), build(nums, m+1, r))
        
        return build(nums, 0, len(nums)-1)
