// @Title: Binary Tree Level Order Traversal
// @Author: colinjxc
// @Date: 2022-02-17T00:22:48+08:00
// @URL: https://leetcode-cn.com/problems/binary-tree-level-order-traversal


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
    res := make([][]int, 0)
    q := make([]*TreeNode, 0)

    q = append(q, root)
    for len(q) > 0 {
        tmp := []int{}
        size := len(q)
        for i := 0; i < size; i++ {
            node := q[i]
            if node != nil {
                tmp = append(tmp, node.Val)
                q = append(q, node.Left, node.Right)
            }
        }
        q = q[size:]
        if len(tmp) > 0 {
            res = append(res, tmp)
        }
    }
    return res;
}
