// @Title: Kth Smallest Element in a BST
// @Author: colinjxc
// @Date: 2022-01-30T19:41:56+08:00
// @URL: https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.cnt = 0
        self.val = 0

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        def inorder(node: Optional[TreeNode]):
            if node == None or self.cnt > k:
                return
            inorder(node.left)
            self.cnt += 1
            if self.cnt == k:
                self.val = node.val
            inorder(node.right)

        inorder(root)
        return self.val
