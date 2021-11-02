// @Title: Maximum Depth of N-ary Tree
// @Author: realzhangm
// @Date: 2021-11-02T15:46:41+08:00
// @URL: https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree


/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func maxDepth(root *Node) int {
    q := []*Node{}
    if root == nil {
        return 0
    }
    depth := 0
    q = append(q, root)

    for {
        levelCnt := len(q)
        if levelCnt == 0 {
            break
        }

        for i := 0; i < levelCnt; i++ {
            for _, childNode := range q[i].Children {
                if childNode != nil {
                    q = append(q, childNode)
                }
            }
        }

        q = q[levelCnt:len(q)]
        depth++
    }
    return depth
}
