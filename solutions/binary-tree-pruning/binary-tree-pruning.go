// @Title: Binary Tree Pruning
// @Author: colinjxc
// @Date: 2022-03-01T21:31:00+08:00
// @URL: https://leetcode-cn.com/problems/binary-tree-pruning


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pruneTree(root *TreeNode) *TreeNode {
    if root == nil {
        return nil
    }
    root.Left = pruneTree(root.Left)
    root.Right = pruneTree(root.Right)
    if root.Left == nil && root.Right == nil && root.Val == 0 {
        return nil
    }
    return root;
}
