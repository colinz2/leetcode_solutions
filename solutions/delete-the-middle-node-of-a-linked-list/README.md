
# [删除链表的中间节点](https://leetcode-cn.com/problems/delete-the-middle-node-of-a-linked-list)

## 题目描述

<p>给你一个链表的头节点 <code>head</code> 。<strong>删除</strong> 链表的 <strong>中间节点</strong> ，并返回修改后的链表的头节点 <code>head</code> 。</p>

<p>长度为 <code>n</code> 链表的中间节点是从头数起第 <code>⌊n / 2⌋</code> 个节点（下标从 <strong>0</strong> 开始），其中 <code>⌊x⌋</code> 表示小于或等于 <code>x</code> 的最大整数。</p>

<ul>
	<li>对于 <code>n</code> = <code>1</code>、<code>2</code>、<code>3</code>、<code>4</code> 和 <code>5</code> 的情况，中间节点的下标分别是 <code>0</code>、<code>1</code>、<code>1</code>、<code>2</code> 和 <code>2</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/11/16/eg1drawio.png" style="width: 500px; height: 77px;" /></p>

<pre>
<strong>输入：</strong>head = [1,3,4,7,1,2,6]
<strong>输出：</strong>[1,3,4,1,2,6]
<strong>解释：</strong>
上图表示给出的链表。节点的下标分别标注在每个节点的下方。
由于 n = 7 ，值为 7 的节点 3 是中间节点，用红色标注。
返回结果为移除节点后的新链表。 
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/11/16/eg2drawio.png" style="width: 250px; height: 43px;" /></p>

<pre>
<strong>输入：</strong>head = [1,2,3,4]
<strong>输出：</strong>[1,2,4]
<strong>解释：</strong>
上图表示给出的链表。
对于 n = 4 ，值为 3 的节点 2 是中间节点，用红色标注。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/11/16/eg3drawio.png" style="width: 150px; height: 58px;" /></p>

<pre>
<strong>输入：</strong>head = [2,1]
<strong>输出：</strong>[2]
<strong>解释：</strong>
上图表示给出的链表。
对于 n = 2 ，值为 1 的节点 1 是中间节点，用红色标注。
值为 2 的节点 0 是移除节点 1 后剩下的唯一一个节点。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目在范围 <code>[1, 10<sup>5</sup>]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


## 题解

### cpp [🔗](delete-the-middle-node-of-a-linked-list.cpp) 
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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode *fast = head->next, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return head;
    }
};
```
### java [🔗](delete-the-middle-node-of-a-linked-list.java) 
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */


class Solution {
    public ListNode deleteMiddle(ListNode head) {
        //快慢指针
        ListNode slow = head,fast = head.next;
        if(fast == null) return null;
        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        slow.next = slow.next.next;
        return head;
    }
}
```


## 相关话题

- [链表](../../tags/linked-list.md) 
- [双指针](../../tags/two-pointers.md) 


## 相似题目



## Links

- [Prev](../richest-customer-wealth/README.md) 
- [Next](../maximum-twin-sum-of-a-linked-list/README.md) 

