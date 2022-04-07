
# [移除链表元素](https://leetcode-cn.com/problems/remove-linked-list-elements)

## 题目描述

给你一个链表的头节点 <code>head</code> 和一个整数 <code>val</code> ，请你删除链表中所有满足 <code>Node.val == val</code> 的节点，并返回 <strong>新的头节点</strong> 。
<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg" style="width: 500px; height: 142px;" />
<pre>
<strong>输入：</strong>head = [1,2,6,3,4,5,6], val = 6
<strong>输出：</strong>[1,2,3,4,5]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = [], val = 1
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>head = [7,7,7,7], val = 7
<strong>输出：</strong>[]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>列表中的节点数目在范围 <code>[0, 10<sup>4</sup>]</code> 内</li>
	<li><code>1 <= Node.val <= 50</code></li>
	<li><code>0 <= val <= 50</code></li>
</ul>


## 题解

### cpp [🔗](remove-linked-list-elements.cpp) 
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr = head;
        ListNode *pre = NULL;
        while (curr) {
            if (curr->val == val) {
                if (pre != NULL)
                    pre->next = curr->next;
                else 
                    head = head->next;
            } else {
                pre = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};
```
### c [🔗](remove-linked-list-elements.c) 
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode **list = &head;
    while (*list != NULL) {
        if ((*list)->val == val) {
            *list = (*list)->next;
        } else {
            list = &(*list)->next;
        }
    }
    return head;
}
```


## 相关话题

- [递归](../../tags/recursion.md) 
- [链表](../../tags/linked-list.md) 


## 相似题目

- [移除元素](../remove-element/README.md)  [Easy] 
- [删除链表中的节点](../delete-node-in-a-linked-list/README.md)  [Easy] 


## Links

- [Prev](../happy-number/README.md) 
- [Next](../count-primes/README.md) 

