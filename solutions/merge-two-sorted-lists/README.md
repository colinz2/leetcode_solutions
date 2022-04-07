
# [合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists)

## 题目描述

<p>将两个升序链表合并为一个新的 <strong>升序</strong> 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 </p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg" style="width: 662px; height: 302px;" />
<pre>
<strong>输入：</strong>l1 = [1,2,4], l2 = [1,3,4]
<strong>输出：</strong>[1,1,2,3,4,4]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>l1 = [], l2 = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>l1 = [], l2 = [0]
<strong>输出：</strong>[0]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>两个链表的节点数目范围是 <code>[0, 50]</code></li>
	<li><code>-100 <= Node.val <= 100</code></li>
	<li><code>l1</code> 和 <code>l2</code> 均按 <strong>非递减顺序</strong> 排列</li>
</ul>


## 题解

### cpp [🔗](merge-two-sorted-lists.cpp) 
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* l3 = &dummy;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                l3->next = list2;
                list2 = list2->next;
            } else {
                l3->next = list1;
                list1 = list1->next;
            }
            l3 = l3->next;
        }
        if (list1) {
            l3->next = list1;
        } else {
            l3->next = list2;
        }

        return dummy.next;
    }
};
```


## 相关话题

- [递归](../../tags/recursion.md) 
- [链表](../../tags/linked-list.md) 


## 相似题目

- [合并K个升序链表](../merge-k-sorted-lists/README.md)  [Hard] 
- [合并两个有序数组](../merge-sorted-array/README.md)  [Easy] 
- [排序链表](../sort-list/README.md)  [Medium] 


## Links

- [Prev](../valid-parentheses/README.md) 
- [Next](../generate-parentheses/README.md) 

