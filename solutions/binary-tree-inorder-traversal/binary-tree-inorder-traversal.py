// @Title: Binary Tree Inorder Traversal
// @Author: colinjxc
// @Date: 2022-02-04T13:13:20+08:00
// @URL: https://leetcode-cn.com/problems/binary-tree-inorder-traversal


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        stack = []
        res = []
        while root or len(stack) > 0:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            res.append(root.val)
            root = root.right
        return res
