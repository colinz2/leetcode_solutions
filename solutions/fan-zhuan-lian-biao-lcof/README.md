
# [反转链表](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof)

## 题目描述

<p>定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。</p>

<p>&nbsp;</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;NULL
<strong>输出:</strong> 5-&gt;4-&gt;3-&gt;2-&gt;1-&gt;NULL</pre>

<p>&nbsp;</p>

<p><strong>限制：</strong></p>

<p><code>0 &lt;= 节点个数 &lt;= 5000</code></p>

<p>&nbsp;</p>

<p><strong>注意</strong>：本题与主站 206 题相同：<a href="https://leetcode-cn.com/problems/reverse-linked-list/">https://leetcode-cn.com/problems/reverse-linked-list/</a></p>


## 题解

### cpp [🔗](fan-zhuan-lian-biao-lcof.cpp) 
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
    ListNode* reverseList(ListNode* head) {
        ListNode* newNode = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = newNode;
            newNode = head;
            head = next;
        }
        return newNode;
    }
};
```


## 相关话题

- [递归](../../tags/recursion.md) 
- [链表](../../tags/linked-list.md) 


## 相似题目



## Links

- [Prev](../lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/README.md) 
- [Next](../shan-chu-lian-biao-de-jie-dian-lcof/README.md) 

