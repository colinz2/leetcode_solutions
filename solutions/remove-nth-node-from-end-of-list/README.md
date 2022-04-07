
# [删除链表的倒数第 N 个结点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list)

## 题目描述

<p>给你一个链表，删除链表的倒数第&nbsp;<code>n</code><em>&nbsp;</em>个结点，并且返回链表的头结点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg" style="width: 542px; height: 222px;" />
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

<p><strong>进阶：</strong>你能尝试使用一趟扫描实现吗？</p>


## 题解

### c [🔗](remove-nth-node-from-end-of-list.c) 
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* fast = head;
    struct ListNode dummy = {.next = head};
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    struct ListNode* pre = &dummy;
    while (fast) {
        fast = fast->next;
        pre = head;
        head = head->next;
    }
    pre->next = head->next;
    free(head);
    return dummy.next;
}
```
### cpp [🔗](remove-nth-node-from-end-of-list.cpp) 
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
        ListNode* fast = head;
        ListNode dummy;
        dummy.next = head;

        for (int i = 0; i < n; i++) {
            if (fast == nullptr) 
                return nullptr;
            fast = fast->next; 
        }
        ListNode* pre = &dummy;
        while (fast) {
            fast = fast->next;
            pre = head;
            head = head->next;
        }
        pre->next = head->next;
        delete head;

        return dummy.next;
    }
};
```


## 相关话题

- [链表](../../tags/linked-list.md) 
- [双指针](../../tags/two-pointers.md) 


## 相似题目



## Links

- [Prev](../letter-combinations-of-a-phone-number/README.md) 
- [Next](../valid-parentheses/README.md) 

