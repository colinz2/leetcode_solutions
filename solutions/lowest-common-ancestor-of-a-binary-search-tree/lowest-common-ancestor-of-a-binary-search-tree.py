// @Title: Lowest Common Ancestor of a Binary Search Tree
// @Author: colinjxc
// @Date: 2022-02-01T04:45:26+08:00
// @URL: https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        while root != None:
            if root.val > max(p.val, q.val):
                root = root.left
            elif root.val < min(p.val, q.val):
                root = root.right
            else: 
                return root
        return root
