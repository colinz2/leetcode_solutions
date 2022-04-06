// @Title: House Robber III
// @Author: colinjxc
// @Date: 2022-01-06T17:00:59+08:00
// @URL: https://leetcode-cn.com/problems/house-robber-iii


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: TreeNode) -> int:
        def rob_(root):
            if root == None:
                return 0, 0
            ls, ln = rob_(root.left)
            rs, rn = rob_(root.right)
            return root.val + ln + rn, max(ls, ln) + max(rs, rn)

        return max(rob_(root))    

