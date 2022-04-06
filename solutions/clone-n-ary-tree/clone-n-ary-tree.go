// @Title: Clone N-ary Tree
// @Author: colinjxc
// @Date: 2022-03-01T21:44:20+08:00
// @URL: https://leetcode-cn.com/problems/clone-n-ary-tree


/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func cloneTree(root *Node) *Node {
	if root == nil {
        return nil
    }
    newRoot := new(Node)
    newRoot.Val = root.Val
    for _, ch := range root.Children {
        newRoot.Children = append(newRoot.Children, cloneTree(ch))
    }

    return newRoot
}
