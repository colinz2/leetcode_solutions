// @Title: Maximum Depth of Binary Tree
// @Author: colinjxc
// @Date: 2021-11-02T12:30:36+08:00
// @URL: https://leetcode-cn.com/problems/maximum-depth-of-binary-tree


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxDepth(root *TreeNode) int {
    if root ==  nil {
        return 0
    }
    return max(maxDepth(root.Left), maxDepth(root.Right)) + 1
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b;
}
