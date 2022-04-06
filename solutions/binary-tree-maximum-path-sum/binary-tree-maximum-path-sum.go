// @Title: Binary Tree Maximum Path Sum
// @Author: colinjxc
// @Date: 2022-02-06T21:12:50+08:00
// @URL: https://leetcode-cn.com/problems/binary-tree-maximum-path-sum


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxPathSum(root *TreeNode) int {
    res := -1<<31
    var dfs func(root *TreeNode) int = nil
    dfs = func(root *TreeNode) int {
        if root == nil {
            return 0
        }
        x := max(0, dfs(root.Left))
        y := max(0, dfs(root.Right))
        res = max(res, x + y + root.Val)
        return max(x, y) + root.Val
    }
    dfs(root)
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
