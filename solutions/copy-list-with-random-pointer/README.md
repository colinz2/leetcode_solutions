
# [](https://leetcode-cn.com/problems/copy-list-with-random-pointer)

## 题目描述



## 题解

### golang [🔗](copy-list-with-random-pointer.go) 
```golang
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
```
### python3 [🔗](copy-list-with-random-pointer.py) 
```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        curr = head
        node_map = dict()
        while curr:
            node_map[curr] = Node(curr.val)
            curr = curr.next
        curr = head
        
        while curr:
            node = node_map[curr]
            if curr.next:
                node.next = node_map[curr.next]
            if curr.random:
                node.random = node_map[curr.random]
            curr = curr.next
        if head == None:
            return None
        return node_map[head]

```
### cpp [🔗](copy-list-with-random-pointer.cpp) 
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> node_map;
        for (auto curr = head; curr; curr = curr->next) {
            node_map[curr] = new Node(curr->val);
        }
        for (auto curr = head; curr; curr = curr->next) {
            auto new_node = node_map[curr];
            new_node->random = node_map[curr->random];
            new_node->next = node_map[curr->next];
        }        
        return node_map[head];
    }
};
```


## 相关话题



## 相似题目



## Links

- [Prev](../single-number/README.md) 
- [Next](../word-break/README.md) 

