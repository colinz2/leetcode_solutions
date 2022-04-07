
# [环形链表](https://leetcode-cn.com/problems/linked-list-cycle)

## 题目描述

<p>给你一个链表的头节点 <code>head</code> ，判断链表中是否有环。</p>

<p>如果链表中有某个节点，可以通过连续跟踪 <code>next</code> 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 <code>pos</code> 来表示链表尾连接到链表中的位置（索引从 0 开始）。<strong>注意：<code>pos</code> 不作为参数进行传递&nbsp;</strong>。仅仅是为了标识链表的实际情况。</p>

<p><em>如果链表中存在环</em>&nbsp;，则返回 <code>true</code> 。 否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png" /></p>

<pre>
<strong>输入：</strong>head = [3,2,0,-4], pos = 1
<strong>输出：</strong>true
<strong>解释：</strong>链表中有一个环，其尾部连接到第二个节点。
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png" /></p>

<pre>
<strong>输入：</strong>head = [1,2], pos = 0
<strong>输出：</strong>true
<strong>解释：</strong>链表中有一个环，其尾部连接到第一个节点。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png" /></p>

<pre>
<strong>输入：</strong>head = [1], pos = -1
<strong>输出：</strong>false
<strong>解释：</strong>链表中没有环。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目范围是 <code>[0, 10<sup>4</sup>]</code></li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li><code>pos</code> 为 <code>-1</code> 或者链表中的一个 <strong>有效索引</strong> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能用 <code>O(1)</code>（即，常量）内存解决此问题吗？</p>


## 题解

### cpp [🔗](linked-list-cycle.cpp) 
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
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        while (fast && head) {
            head = head->next;
            if (fast->next)
                fast = fast->next->next;
            else
                break;
            if (head == fast) return true;
        }
        return false;
    }
};
```
### golang [🔗](linked-list-cycle.go) 
```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
    fast := head
    for fast != nil && fast.Next != nil {
        head = head.Next
        fast = fast.Next.Next
        if fast == head {
            return true
        }
    }
    return false
}
```
### java [🔗](linked-list-cycle.java) 
```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            head = head.next;
            if (head == fast) {
                return true;
            }
        }
        return false;
    }
}
```
### python3 [🔗](linked-list-cycle.py) 
```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast = head
        while fast != None and fast.next != None:
            fast = fast.next.next
            head = head.next
            if fast == head:
                return True
        return False
```
### typescript [🔗](linked-list-cycle.ts) 
```typescript
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function hasCycle(head: ListNode | null): boolean {
    let fast = head
    while (fast != null && fast.next != null) {
        fast = fast.next.next
        head = head.next
        if (head === fast) {
            return true
        }
    }
    return false
};
```
### c [🔗](linked-list-cycle.c) 
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        head = head->next;
        if (head == fast) {
            return true;
        }
    } 
    return false;
}
```


## 相关话题

- [哈希表](../../tags/hash-table.md) 
- [链表](../../tags/linked-list.md) 
- [双指针](../../tags/two-pointers.md) 


## 相似题目

- [环形链表 II](../linked-list-cycle-ii/README.md)  [Medium] 
- [快乐数](../happy-number/README.md)  [Easy] 


## Links

- [Prev](../word-break/README.md) 
- [Next](../linked-list-cycle-ii/README.md) 

