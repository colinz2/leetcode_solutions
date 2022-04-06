// @Title: Univalued Binary Tree
// @Author: colinjxc
// @Date: 2022-03-01T18:25:25+08:00
// @URL: https://leetcode-cn.com/problems/univalued-binary-tree


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isUnivalTree(root *TreeNode) bool {
    if root == nil {
        return true
    }
    return dfsCheck(root, root.Val)
}

func dfsCheck(root *TreeNode, val int) bool {
    if root == nil {
        return true
    }
    if root.Val != val {
        return false
    }
    return dfsCheck(root.Left, val) && dfsCheck(root.Right, val)
}
