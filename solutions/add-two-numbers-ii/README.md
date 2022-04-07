
# [两数相加 II](https://leetcode-cn.com/problems/add-two-numbers-ii)

## 题目描述

<p>给你两个 <strong>非空 </strong>链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。</p>

<p>你可以假设除了数字 0 之外，这两个数字都不会以零开头。</p>

<p>&nbsp;</p>

<p><strong>示例1：</strong></p>

<p><img alt="" src="https://pic.leetcode-cn.com/1626420025-fZfzMX-image.png" style="width: 302px; " /></p>

<pre>
<strong>输入：</strong>l1 = [7,2,4,3], l2 = [5,6,4]
<strong>输出：</strong>[7,8,0,7]
</pre>

<p><strong>示例2：</strong></p>

<pre>
<strong>输入：</strong>l1 = [2,4,3], l2 = [5,6,4]
<strong>输出：</strong>[8,0,7]
</pre>

<p><strong>示例3：</strong></p>

<pre>
<strong>输入：</strong>l1 = [0], l2 = [0]
<strong>输出：</strong>[0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表的长度范围为<code> [1, 100]</code></li>
	<li><code>0 &lt;= node.val &lt;= 9</code></li>
	<li>输入数据保证链表代表的数字无前导 0</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>如果输入链表不能翻转该如何解决？</p>


## 题解

### cpp [🔗](add-two-numbers-ii.cpp) 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        stack<int> s1, s2;

        while (l1) s1.push(l1->val), l1 = l1->next;
        while (l2) s2.push(l2->val), l2 = l2->next;
        
        int add = 0;
        while (!s1.empty() || !s2.empty() || add) {
            if (!s1.empty()) {
                add += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                add += s2.top();
                s2.pop();
            }
            ListNode* node = new ListNode(add % 10, dummy.next);
            dummy.next = node;
            add = add / 10;
        }
        return dummy.next;
    }
};
```


## 相关话题

- [栈](../../tags/stack.md) 
- [链表](../../tags/linked-list.md) 
- [数学](../../tags/math.md) 


## 相似题目

- [两数相加](../add-two-numbers/README.md)  [Medium] 


## Links

- [Prev](../string-compression/README.md) 
- [Next](../find-all-numbers-disappeared-in-an-array/README.md) 

