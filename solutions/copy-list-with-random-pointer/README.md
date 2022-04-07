
# [复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer)

## 题目描述

<p>给你一个长度为 <code>n</code> 的链表，每个节点包含一个额外增加的随机指针 <code>random</code> ，该指针可以指向链表中的任何节点或空节点。</p>

<p>构造这个链表的&nbsp;<strong><a href="https://baike.baidu.com/item/深拷贝/22785317?fr=aladdin" target="_blank">深拷贝</a></strong>。&nbsp;深拷贝应该正好由 <code>n</code> 个 <strong>全新</strong> 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 <code>next</code> 指针和 <code>random</code> 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。<strong>复制链表中的指针都不应指向原链表中的节点 </strong>。</p>

<p>例如，如果原链表中有 <code>X</code> 和 <code>Y</code> 两个节点，其中 <code>X.random --&gt; Y</code> 。那么在复制链表中对应的两个节点 <code>x</code> 和 <code>y</code> ，同样有 <code>x.random --&gt; y</code> 。</p>

<p>返回复制链表的头节点。</p>

<p>用一个由&nbsp;<code>n</code>&nbsp;个节点组成的链表来表示输入/输出中的链表。每个节点用一个&nbsp;<code>[val, random_index]</code>&nbsp;表示：</p>

<ul>
	<li><code>val</code>：一个表示&nbsp;<code>Node.val</code>&nbsp;的整数。</li>
	<li><code>random_index</code>：随机指针指向的节点索引（范围从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n-1</code>）；如果不指向任何节点，则为&nbsp;&nbsp;<code>null</code>&nbsp;。</li>
</ul>

<p>你的代码 <strong>只</strong> 接受原链表的头节点 <code>head</code> 作为传入参数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/09/e1.png" style="height: 142px; width: 700px;" /></p>

<pre>
<strong>输入：</strong>head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
<strong>输出：</strong>[[7,null],[13,0],[11,4],[10,2],[1,0]]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/09/e2.png" style="height: 114px; width: 700px;" /></p>

<pre>
<strong>输入：</strong>head = [[1,1],[2,1]]
<strong>输出：</strong>[[1,1],[2,1]]
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/09/e3.png" style="height: 122px; width: 700px;" /></strong></p>

<pre>
<strong>输入：</strong>head = [[3,null],[3,0],[3,null]]
<strong>输出：</strong>[[3,null],[3,0],[3,null]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 1000</code><meta charset="UTF-8" /></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li><code>Node.random</code>&nbsp;为&nbsp;<code>null</code> 或指向链表中的节点。</li>
</ul>


## 题解

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


## 相关话题

- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [链表](https://leetcode-cn.com/tag/linked-list) 


## 相似题目



## Links

- [Prev](../single-number/README.md) 
- [Next](../word-break/README.md) 

