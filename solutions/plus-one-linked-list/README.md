
# [给单链表加一](https://leetcode-cn.com/problems/plus-one-linked-list)

## 题目描述

<p>给定一个用<strong>链表</strong>表示的非负整数， 然后将这个整数&nbsp;<em>再加上 1</em> 。</p>

<p>这些数字的存储是这样的：最高位有效的数字位于链表的首位<meta charset="UTF-8" />&nbsp;<code>head</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong>head = [1,2,3]
<strong>输出: </strong>[1,2,4]
</pre>

<p><meta charset="UTF-8" /></p>

<p><strong>示例</strong><strong>&nbsp;2:</strong></p>

<pre>
<strong>输入: </strong>head = [0]
<strong>输出: </strong>[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中的节点数在<meta charset="UTF-8" />&nbsp;<code>[1, 100]</code>&nbsp;的范围内。</li>
	<li><code>0 &lt;= Node.val &lt;= 9</code></li>
	<li>由链表表示的数字不包含前导零，除了零本身。</li>
</ul>


## 题解

### cpp [🔗](plus-one-linked-list.cpp) 
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
    ListNode* plusOne(ListNode* head) {
        std::stack<ListNode*> stack;
        ListNode* head2 = head;
        while (head) {
            stack.push(head);
            head = head->next;
        }
        int add = 1;
        while (!stack.empty()) {
            int tmp = stack.top()->val + add; 
            add = tmp / 10;
            stack.top()->val = tmp % 10;
            stack.pop();
        }
        if (add) {
            auto newHead = new ListNode(add, head2);
            return newHead;
        }

        return head2;
    }
};
```


## 相关话题

- [链表](../../tags/linked-list.md) 
- [数学](../../tags/math.md) 


## 相似题目

- [加一](../plus-one/README.md)  [Easy] 


## Links

- [Prev](../valid-perfect-square/README.md) 
- [Next](../sum-of-two-integers/README.md) 

