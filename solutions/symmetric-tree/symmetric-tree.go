// @Title: Symmetric Tree
// @Author: colinjxc
// @Date: 2021-07-23T18:39:42+08:00
// @URL: https://leetcode-cn.com/problems/symmetric-tree


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSymmetric(root *TreeNode) bool {
    if root == nil {
        return true
    }
    return isSym(root.Left, root.Right)
}

func isSym(left, right *TreeNode) bool {
    if left == nil && right ==  nil {
        return true
    } 

    if left == nil || right == nil  {
        return false
    }

    if left.Val != right.Val {
        return false
    } else {
        return isSym(left.Left, right.Right) && isSym(left.Right, right.Left)
    }
}
