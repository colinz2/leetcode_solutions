// @Title: Copy List with Random Pointer
// @Author: colinjxc
// @Date: 2022-02-05T21:51:23+08:00
// @URL: https://leetcode-cn.com/problems/copy-list-with-random-pointer


/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
    node_map := make(map[*Node]*Node)
    for curr := head; curr != nil; curr = curr.Next {
        node_map[curr] = &Node{Val:curr.Val}
    }

    for curr := head; curr != nil; curr = curr.Next {
        node := node_map[curr]
        if curr.Next != nil {
            node.Next = node_map[curr.Next]
        }
        if curr.Random != nil {
            node.Random = node_map[curr.Random]
        }
    }
    return node_map[head]
}
