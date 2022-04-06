// @Title: Diameter of Binary Tree
// @Author: colinjxc
// @Date: 2022-03-01T18:21:12+08:00
// @URL: https://leetcode-cn.com/problems/diameter-of-binary-tree


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func diameterOfBinaryTree(root *TreeNode) int {
    diameter := 0
    depth(root, &diameter)
    return diameter
}

func depth(root *TreeNode, diameter *int) int {
    if root == nil {
        return 0
    }
    le := depth(root.Left, diameter)
    ri := depth(root.Right, diameter)
    *diameter = max(*diameter, le + ri)
    return max(le, ri) + 1
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}


