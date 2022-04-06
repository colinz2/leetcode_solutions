// @Title: Binary Tree Level Order Traversal II
// @Author: colinjxc
// @Date: 2021-11-02T13:24:47+08:00
// @URL: https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrderBottom(root *TreeNode) [][]int {
    res := [][]int{}
    if root == nil {
        return res
    }
    q := []*TreeNode{}
    q = append(q, root)
    for {
        levelLen := len(q)
        if levelLen == 0 {
            break;
        }
        levelVec := make([]int, 0, levelLen)
        for i := 0; i < levelLen; i++ {
            levelVec = append(levelVec, q[i].Val)
            if q[i].Left != nil {
                q = append(q, q[i].Left)
            }

            if q[i].Right != nil {
                q = append(q, q[i].Right)
            }
        }
        res = append(res, levelVec)
        q = q[levelLen: len(q)]
    }
    reverse(res)
    return res;
}

func reverse(vec [][]int) {
    l, r := 0, len(vec)
    if r == 0 {
        return 
    } else {
        r--
    }

    for (l < r) {
        vec[l], vec[r] = vec[r], vec[l]
        l++
        r--
    }
}


