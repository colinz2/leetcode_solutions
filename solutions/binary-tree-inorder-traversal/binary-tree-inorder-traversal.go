// @Title: Binary Tree Inorder Traversal
// @Author: colinjxc
// @Date: 2021-07-07T11:54:48+08:00
// @URL: https://leetcode-cn.com/problems/binary-tree-inorder-traversal


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int {
	res := []int{}
	var inorder func(*TreeNode)

	inorder = func(n *TreeNode) {
		if n == nil {
			return
		}
		inorder(n.Left)
		res = append(res, n.Val)
		inorder(n.Right)
	}

	inorder(root)
	return res
}

