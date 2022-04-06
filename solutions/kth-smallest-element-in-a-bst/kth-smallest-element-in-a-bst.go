// @Title: Kth Smallest Element in a BST
// @Author: colinjxc
// @Date: 2022-01-30T20:44:43+08:00
// @URL: https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthSmallest(root *TreeNode, k int) int {
    stack := make([]*TreeNode, 0)
    for root != nil || len(stack) > 0 {
        for root != nil {
            stack = append(stack, root)
            root = root.Left
        }
        root = stack[len(stack)-1]
        stack = stack[0:len(stack)-1]
        k--
        if k == 0 {
            return root.Val
        }
        root = root.Right
    }
    return 0
}
