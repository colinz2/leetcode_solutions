
# [](https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list)

## 题目描述



## 题解

### golang [🔗](flatten-a-multilevel-doubly-linked-list.go) 
```golang
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
```


## 相关话题



## 相似题目



## Links

- [Prev](../n-ary-tree-level-order-traversal/README.md) 
- [Next](../maximum-depth-of-n-ary-tree/README.md) 

