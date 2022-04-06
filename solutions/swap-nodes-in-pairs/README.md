
# [两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs)

## 题目描述

<p>给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg" style="width: 422px; height: 222px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,4]
<strong>输出：</strong>[2,1,4,3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>head = [1]
<strong>输出：</strong>[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目在范围 <code>[0, 100]</code> 内</li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
</ul>


## 题解

### cpp [🔗](swap-nodes-in-pairs.cpp) 
```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode dummy(0);
        dummy.next = head;

        ListNode* pre = &dummy;
        ListNode* curr = pre->next;
        while (curr) {
            ListNode* next = curr->next;
            if (next) {
                pre->next = next;
                curr->next = next->next;
                next->next = curr;

                pre = curr;
                curr = curr->next;
            } else {
                break;
            }
        }
        return dummy.next;
    }
};
```


## 相关话题

- [递归](https://leetcode-cn.com/tag/recursion) 
- [链表](https://leetcode-cn.com/tag/linked-list) 


## 相似题目

- [K 个一组翻转链表](../reverse-nodes-in-k-group/README.md)  [Hard] 


## Links

- [Prev](../merge-k-sorted-lists/README.md) 
- [Next](../reverse-nodes-in-k-group/README.md) 

