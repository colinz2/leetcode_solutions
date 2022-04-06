// @Title: Range Sum of BST
// @Author: colinjxc
// @Date: 2022-02-05T03:26:47+08:00
// @URL: https://leetcode-cn.com/problems/range-sum-of-bst


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rangeSumBST(root *TreeNode, low int, high int) int {
    res := 0
    stack := []*TreeNode{}
    for root != nil || len(stack) > 0 {
        for root != nil {
            stack = append(stack, root)
            root = root.Left
        }
        root = stack[len(stack) - 1]
        stack = stack[:len(stack) - 1]
        if (root.Val >= low && root.Val <= high) {
            res += root.Val
        } else if (root.Val > high) {
            // 可以提前退出
            break;
        }
        root = root.Right
    }
    return res
}
