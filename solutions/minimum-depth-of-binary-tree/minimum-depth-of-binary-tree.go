// @Title: Minimum Depth of Binary Tree
// @Author: colinjxc
// @Date: 2021-11-02T13:00:34+08:00
// @URL: https://leetcode-cn.com/problems/minimum-depth-of-binary-tree


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func minDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    if root.Left == nil && root.Right == nil {
        return 1
    }

    lMinDepth := minDepth(root.Left)
    rMinDepth := minDepth(root.Right)
    if lMinDepth == 0 {
        // 左子树为空
        return rMinDepth + 1
    } 
    if rMinDepth == 0 {
        // 右子树为空
        return lMinDepth + 1
    }
    return min(lMinDepth, rMinDepth) + 1
}

func min(a, b int) int {
    if a > b {
        return b
    }
    return a
}
