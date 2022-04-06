
# [删除链表的倒数第 n 个结点](https://leetcode-cn.com/problems/SLwz0R)

## 题目描述

<p>给定一个链表，删除链表的倒数第&nbsp;<code>n</code><em>&nbsp;</em>个结点，并且返回链表的头结点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg" style="width: 542px; height: 222px;" /></p>

<pre>
<strong>输入：</strong>head = [1,2,3,4,5], n = 2
<strong>输出：</strong>[1,2,3,5]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = [1], n = 1
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>head = [1,2], n = 1
<strong>输出：</strong>[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中结点的数目为 <code>sz</code></li>
	<li><code>1 &lt;= sz &lt;= 30</code></li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
	<li><code>1 &lt;= n &lt;= sz</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>能尝试使用一趟扫描实现吗？</p>

<p>&nbsp;</p>

<p><meta charset="UTF-8" />注意：本题与主站 19&nbsp;题相同：&nbsp;<a href="https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/">https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/</a></p>


## 题解

### cpp [🔗](SLwz0R.cpp) 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;
        ListNode dummy(-1, head);
        ListNode *fast = head, *slow = &dummy;
        for (int i = 0; i < n && fast != nullptr; i++) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        auto next = slow->next->next;
        delete slow->next;
        slow->next = next;

        return dummy.next;
    }
};
```


## 相关话题

- [链表](https://leetcode-cn.com/tag/linked-list) 
- [双指针](https://leetcode-cn.com/tag/two-pointers) 


## 相似题目



## Links

- [Prev](../kth-node-from-end-of-list-lcci/README.md) 
- [Next](../UHnkqh/README.md) 

