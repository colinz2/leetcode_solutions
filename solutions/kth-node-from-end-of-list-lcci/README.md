
# [返回倒数第 k 个节点](https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci)

## 题目描述

<p>实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。</p>

<p><strong>注意：</strong>本题相对原题稍作改动</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong> 1-&gt;2-&gt;3-&gt;4-&gt;5 和 <em>k</em> = 2
<strong>输出： </strong>4</pre>

<p><strong>说明：</strong></p>

<p>给定的 <em>k</em>&nbsp;保证是有效的。</p>


## 题解

### cpp [🔗](kth-node-from-end-of-list-lcci.cpp) 
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* n1 = head, *n2 = head;
        int i = 0;
        for (; i < k && n1 != nullptr; i++) {
            n1 = n1->next;
        }
        if (n1 == nullptr && i < k) {
            return -1;
        }
        while (n1) {
            n1 = n1->next;
            n2 = n2->next;
        }
        return n2->val;
    }
};
```
### python [🔗](kth-node-from-end-of-list-lcci.py) 
```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def kthToLast(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: int
        """
        node_list = []
        while head:
            node_list.append(head.val)
            head = head.next
        return node_list[-k]
```
### python3 [🔗](kth-node-from-end-of-list-lcci.py) 
```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        node_list = []
        while head:
            node_list.append(head.val)
            head = head.next
        return node_list[-k]
```


## 相关话题

- [链表](https://leetcode-cn.com/tag/linked-list) 
- [双指针](https://leetcode-cn.com/tag/two-pointers) 


## 相似题目



## Links

- [Prev](../maximum-lcci/README.md) 
- [Next](../SLwz0R/README.md) 

