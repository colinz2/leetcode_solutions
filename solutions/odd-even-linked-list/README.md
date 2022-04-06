
# [奇偶链表](https://leetcode-cn.com/problems/odd-even-linked-list)

## 题目描述

<p>给定单链表的头节点&nbsp;<code>head</code>&nbsp;，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。</p>

<p><strong>第一个</strong>节点的索引被认为是 <strong>奇数</strong> ， <strong>第二个</strong>节点的索引为&nbsp;<strong>偶数</strong> ，以此类推。</p>

<p>请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。</p>

<p>你必须在&nbsp;<code>O(1)</code>&nbsp;的额外空间复杂度和&nbsp;<code>O(n)</code>&nbsp;的时间复杂度下解决这个问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2021/03/10/oddeven-linked-list.jpg" style="height: 123px; width: 300px;" /></p>

<pre>
<strong>输入: </strong>head = [1,2,3,4,5]
<strong>输出:</strong>&nbsp;[1,3,5,2,4]</pre>

<p><strong>示例 2:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2021/03/10/oddeven2-linked-list.jpg" style="height: 142px; width: 500px;" /></p>

<pre>
<strong>输入:</strong> head = [2,1,3,5,6,4,7]
<strong>输出:</strong> [2,3,6,7,1,5,4]</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n ==&nbsp;</code> 链表中的节点数</li>
	<li><code>0 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>6</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>6</sup></code></li>
</ul>


## 题解

### c [🔗](odd-even-linked-list.c) 
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if (head == NULL) return NULL;
    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* evenHead = even;
    while (even != NULL && even->next != NULL) {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
```
### cpp [🔗](odd-even-linked-list.cpp) 
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* odd = head;
        ListNode* evenHead = odd->next;
        ListNode* even = evenHead;
        while (even != nullptr && even->next != nullptr) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            even = even->next;
            odd = odd->next;
        }
        odd->next = evenHead;
        return head;
    }
};
```
### python3 [🔗](odd-even-linked-list.py) 
```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if head == None:
            return head
        odd = head
        even = head.next
        even_head = even
        while even and even.next and odd.next:
            odd.next = odd.next.next
            even.next = even.next.next
            odd = odd.next
            even = even.next
        odd.next = even_head
        return head        
```


## 相关话题

- [链表](https://leetcode-cn.com/tag/linked-list) 


## 相似题目

- [分隔链表](../split-linked-list-in-parts/README.md)  [Medium] 


## Links

- [Prev](../power-of-three/README.md) 
- [Next](../house-robber-iii/README.md) 

