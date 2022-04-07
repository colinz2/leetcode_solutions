
# [反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii)

## 题目描述

给你单链表的头指针 <code>head</code> 和两个整数 <code>left</code> 和 <code>right</code> ，其中 <code>left <= right</code> 。请你反转从位置 <code>left</code> 到位置 <code>right</code> 的链表节点，返回 <strong>反转后的链表</strong> 。
<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,4,5], left = 2, right = 4
<strong>输出：</strong>[1,4,3,2,5]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = [5], left = 1, right = 1
<strong>输出：</strong>[5]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点数目为 <code>n</code></li>
	<li><code>1 <= n <= 500</code></li>
	<li><code>-500 <= Node.val <= 500</code></li>
	<li><code>1 <= left <= right <= n</code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong> 你可以使用一趟扫描完成反转吗？</p>


## 题解

### c [🔗](reverse-linked-list-ii.c) 
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode dummy = {.next = head};
    struct ListNode *curr = head, *pre = &dummy, *next;
    int index = 0;
    while (curr) {
        if (++index >= left && index < right) {
            next = curr->next;
            curr->next = next->next;
            next->next = pre->next;
            pre->next = next;
        } else {
            pre = curr;
            curr = curr->next;
        }
    }
    return dummy.next;
}
```
### cpp [🔗](reverse-linked-list-ii.cpp) 
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;

        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }
        ListNode *curr = pre->next;
        for (int i = left; i < right; ++i) {
            ListNode *t = curr->next;
            curr->next = t->next;
            t->next = pre->next;
            pre->next = t;
        }
        return dummy->next;
    }
};
```


## 相关话题

- [链表](https://leetcode-cn.com/tag/linked-list) 


## 相似题目

- [反转链表](../reverse-linked-list/README.md)  [Easy] 


## Links

- [Prev](../subsets-ii/README.md) 
- [Next](../restore-ip-addresses/README.md) 

