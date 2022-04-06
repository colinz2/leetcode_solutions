
# [分隔链表](https://leetcode-cn.com/problems/partition-list)

## 题目描述

<p>给你一个链表的头节点 <code>head</code> 和一个特定值<em> </em><code>x</code> ，请你对链表进行分隔，使得所有 <strong>小于</strong> <code>x</code> 的节点都出现在 <strong>大于或等于</strong> <code>x</code> 的节点之前。</p>

<p>你应当 <strong>保留</strong> 两个分区中每个节点的初始相对位置。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/partition.jpg" style="width: 662px; height: 222px;" />
<pre>
<strong>输入：</strong>head = [1,4,3,2,5,2], x = 3
<strong>输出</strong>：[1,2,2,4,3,5]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = [2,1], x = 2
<strong>输出</strong>：[1,2]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目在范围 <code>[0, 200]</code> 内</li>
	<li><code>-100 <= Node.val <= 100</code></li>
	<li><code>-200 <= x <= 200</code></li>
</ul>


## 题解

### cpp [🔗](partition-list.cpp) 
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return nullptr;
        ListNode gHead, dummy;
        dummy.next = head;
        ListNode *curr = &dummy, *g = &gHead;
        while (curr->next) {
            if (curr->next->val >= x) {
                g->next = curr->next;
                curr->next = curr->next->next;
                g = g->next;
            } else {
                curr = curr->next;
            }
        }
        g->next = nullptr;
        curr->next = gHead.next;
        return dummy.next;
    }
};
```


## 相关话题

- [链表](https://leetcode-cn.com/tag/linked-list) 
- [双指针](https://leetcode-cn.com/tag/two-pointers) 


## 相似题目



## Links

- [Prev](../largest-rectangle-in-histogram/README.md) 
- [Next](../merge-sorted-array/README.md) 

