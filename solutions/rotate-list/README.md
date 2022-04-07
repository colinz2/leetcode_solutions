
# [旋转链表](https://leetcode-cn.com/problems/rotate-list)

## 题目描述

<p>给你一个链表的头节点 <code>head</code> ，旋转链表，将链表每个节点向右移动&nbsp;<code>k</code><em>&nbsp;</em>个位置。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg" style="width: 450px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,4,5], k = 2
<strong>输出：</strong>[4,5,1,2,3]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/roate2.jpg" style="width: 305px; height: 350px;" />
<pre>
<strong>输入：</strong>head = [0,1,2], k = 4
<strong>输出：</strong>[2,0,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目在范围 <code>[0, 500]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= 2 * 10<sup>9</sup></code></li>
</ul>


## 题解

### python3 [🔗](rotate-list.py) 
```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head == None:
            return head
        last = head
        list_len = 1
        while last.next:
            last = last.next
            list_len += 1
        # link to head
        last.next = head
        for _ in range(0, list_len - (k % list_len)):
            last = last.next
        head = last.next
        last.next = None
        return head
```
### cpp [🔗](rotate-list.cpp) 
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode* last = head;
        int list_len = 1;
        for (; last->next; list_len++, last = last->next );
        last->next = head;

        for (int i = 0; i < list_len - (k % list_len); i++) {
            last = last->next;
        }
        head = last->next;
        last->next = nullptr;
        return head;
    }
};
```
### golang [🔗](rotate-list.go) 
```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
    last := head
    if last == nil {
        return nil
    }
    listLen := 1
    for last.Next != nil {
        listLen++
        last = last.Next;
    }
    last.Next = head;
    for i := 0; i < listLen - (k % listLen); i++ {
        last = last.Next
    }
    head = last.Next
    last.Next = nil
    return head 
}
```
### c [🔗](rotate-list.c) 
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if (head == NULL) return NULL;
    struct ListNode *last = head;
    int list_len = 1;
    while (last->next) {
        list_len++;
        last = last->next;
    }
    last->next = head;
    for (int i = 0; i < list_len - (k % list_len); i++) {
        last = last->next;
    }
    head = last->next;
    last->next = NULL;
    return head;
}
```


## 相关话题

- [链表](../../tags/linked-list.md) 
- [双指针](../../tags/two-pointers.md) 


## 相似题目

- [轮转数组](../rotate-array/README.md)  [Medium] 
- [分隔链表](../split-linked-list-in-parts/README.md)  [Medium] 


## Links

- [Prev](../spiral-matrix-ii/README.md) 
- [Next](../unique-paths/README.md) 

