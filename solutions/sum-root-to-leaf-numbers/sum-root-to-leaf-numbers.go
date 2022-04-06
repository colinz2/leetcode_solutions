// @Title: Sum Root to Leaf Numbers
// @Author: colinjxc
// @Date: 2022-02-06T22:17:23+08:00
// @URL: https://leetcode-cn.com/problems/sum-root-to-leaf-numbers


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */


func sumNumbers(root *TreeNode) int {
    return helper(root, 0)
}

func helper(root *TreeNode, prev int) int {
    if root == nil {
        return 0
    }
    sum := 10*prev + root.Val
    if root.Left == nil && root.Right == nil {
        return sum
    }
    return helper(root.Left, sum) + helper(root.Right, sum)
}
