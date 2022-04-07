
# [合并两个排序的链表](https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof)

## 题目描述

<p>输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。</p>

<p><strong>示例1：</strong></p>

<pre><strong>输入：</strong>1-&gt;2-&gt;4, 1-&gt;3-&gt;4
<strong>输出：</strong>1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4</pre>

<p><strong>限制：</strong></p>

<p><code>0 &lt;= 链表长度 &lt;= 1000</code></p>

<p>注意：本题与主站 21 题相同：<a href="https://leetcode-cn.com/problems/merge-two-sorted-lists/">https://leetcode-cn.com/problems/merge-two-sorted-lists/</a></p>


## 题解

### cpp [🔗](he-bing-liang-ge-pai-xu-de-lian-biao-lcof.cpp) 
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* l3 = &dummy;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                l3->next = l2;
                l2 = l2->next;
            } else {
                l3->next = l1;
                l1 = l1->next;
            }
            l3 = l3->next;
        }
        if (l1) {
            l3->next = l1;
        } else if (l2) {
            l3->next = l2;
        }
        return dummy.next;
    }
};
```


## 相关话题

- [递归](https://leetcode-cn.com/tag/recursion) 
- [链表](https://leetcode-cn.com/tag/linked-list) 


## 相似题目



## Links

- [Prev](../cong-wei-dao-tou-da-yin-lian-biao-lcof/README.md) 
- [Next](../er-jin-zhi-zhong-1de-ge-shu-lcof/README.md) 

