
# [删除排序链表中的重复元素 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii)

## 题目描述

<p>给定一个已排序的链表的头&nbsp;<code>head</code> ，&nbsp;<em>删除原始链表中所有重复数字的节点，只留下不同的数字</em>&nbsp;。返回 <em>已排序的链表</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/linkedlist1.jpg" style="height: 142px; width: 500px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,3,4,4,5]
<strong>输出：</strong>[1,2,5]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/linkedlist2.jpg" style="height: 164px; width: 400px;" />
<pre>
<strong>输入：</strong>head = [1,1,1,2,3]
<strong>输出：</strong>[2,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点数目在范围 <code>[0, 300]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li>题目数据保证链表已经按升序 <strong>排列</strong></li>
</ul>


## 题解

### cpp [🔗](remove-duplicates-from-sorted-list-ii.cpp) 
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy, *curr = head;

        while (curr) {
            ListNode* next = curr->next;
            if (next == NULL) break;
            if (curr->val == next->val) {
                while (next && curr->val == next->val) {
                    next = next->next;
                }
                pre->next = next;
                curr = next;
            } else {
                pre = curr;
                curr = next;
            }
        }
        return dummy.next;
    }
};
```


## 相关话题

- [链表](https://leetcode-cn.com/tag/linked-list) 
- [双指针](https://leetcode-cn.com/tag/two-pointers) 


## 相似题目

- [删除排序链表中的重复元素](../remove-duplicates-from-sorted-list/README.md)  [Easy] 


## Links

- [Prev](../remove-duplicates-from-sorted-array-ii/README.md) 
- [Next](../remove-duplicates-from-sorted-list/README.md) 

