
# [K 个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group)

## 题目描述

<p>给你一个链表，每 <em>k </em>个节点一组进行翻转，请你返回翻转后的链表。</p>

<p><em>k </em>是一个正整数，它的值小于或等于链表的长度。</p>

<p>如果节点总数不是 <em>k </em>的整数倍，那么请将最后剩余的节点保持原有顺序。</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你可以设计一个只使用常数额外空间的算法来解决此问题吗？</li>
	<li><strong>你不能只是单纯的改变节点内部的值</strong>，而是需要实际进行节点交换。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,4,5], k = 2
<strong>输出：</strong>[2,1,4,3,5]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,4,5], k = 3
<strong>输出：</strong>[3,2,1,4,5]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>head = [1,2,3,4,5], k = 1
<strong>输出：</strong>[1,2,3,4,5]
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>head = [1], k = 1
<strong>输出：</strong>[1]
</pre>

<ul>
</ul>

<p><strong>提示：</strong></p>

<ul>
	<li>列表中节点的数量在范围 <code>sz</code> 内</li>
	<li><code>1 <= sz <= 5000</code></li>
	<li><code>0 <= Node.val <= 1000</code></li>
	<li><code>1 <= k <= sz</code></li>
</ul>


## 题解

### cpp [🔗](reverse-nodes-in-k-group.cpp) 
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int list_len = 0;
        ListNode dummy;
        dummy.next = head;
        while (head) {
            head = head->next;
            list_len++;
        }

        ListNode* pre = &dummy;
        head = dummy.next;
        for (int i = 0; i < list_len / k; i++) {
            for (int j = 1; j < k; j++) {
                auto next = head->next;
                head->next = head->next->next;
                next->next = pre->next;
                pre->next = next;
            }
            pre = head;
            head = head->next;
        }

        return dummy.next;
    }
};
```


## 相关话题

- [递归](https://leetcode-cn.com/tag/recursion) 
- [链表](https://leetcode-cn.com/tag/linked-list) 


## 相似题目

- [两两交换链表中的节点](../swap-nodes-in-pairs/README.md)  [Medium] 


## Links

- [Prev](../swap-nodes-in-pairs/README.md) 
- [Next](../remove-duplicates-from-sorted-array/README.md) 

