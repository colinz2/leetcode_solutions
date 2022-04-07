
# [链表求和](https://leetcode-cn.com/problems/sum-lists-lcci)

## 题目描述

<p>给定两个用链表表示的整数，每个节点包含一个数位。</p>

<p>这些数位是反向存放的，也就是个位排在链表首部。</p>

<p>编写函数对这两个整数求和，并用链表形式返回结果。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>(7 -&gt; 1 -&gt; 6) + (5 -&gt; 9 -&gt; 2)，即617 + 295
<strong>输出：</strong>2 -&gt; 1 -&gt; 9，即912
</pre>

<p><strong>进阶：</strong>思考一下，假设这些数位是正向存放的，又该如何解决呢?</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>(6 -&gt; 1 -&gt; 7) + (2 -&gt; 9 -&gt; 5)，即617 + 295
<strong>输出：</strong>9 -&gt; 1 -&gt; 2，即912
</pre>


## 题解

### cpp [🔗](sum-lists-lcci.cpp) 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add = 0, val1 = 0, val2 = 0;
        ListNode dummy;
        ListNode* l3 = &dummy;
        while (l1 || l2 || add) {
            val1 = 0, val2 = 0;
            if (l1) {
                val1 = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val2 = l2->val;
                l2 = l2->next;
            }

            add += val1 + val2;
            l3->next = new ListNode(add %10), l3 = l3->next;
            add /= 10;
        }
        return dummy.next;
    }
};
```


## 相关话题

- [递归](../../tags/recursion.md) 
- [链表](../../tags/linked-list.md) 
- [数学](../../tags/math.md) 


## 相似题目



## Links

- [Prev](../minimum-height-tree-lcci/README.md) 
- [Next](../yong-liang-ge-zhan-shi-xian-dui-lie-lcof/README.md) 

