// @Title: Flatten a Multilevel Doubly Linked List
// @Author: colinjxc
// @Date: 2022-02-03T22:31:06+08:00
// @URL: https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list


/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Prev *Node
 *     Next *Node
 *     Child *Node
 * }
 */

func flatten(root *Node) *Node {
    var last *Node = nil
    var flat func(*Node)

    flat = func(node *Node) {
        if node == nil {
            return
        }
        next := node.Next
        if last != nil {
            node.Prev = last
            last.Next = node
            last.Child = nil
        }
        last = node
        flat(node.Child)
        flat(next)
    }
    
    flat(root)
    return root
}
