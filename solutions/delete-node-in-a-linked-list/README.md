
# [删除链表中的节点](https://leetcode-cn.com/problems/delete-node-in-a-linked-list)

## 题目描述

<p>请编写一个函数，用于 <strong>删除单链表中某个特定节点</strong> 。在设计函数时需要注意，你无法访问链表的头节点&nbsp;<code>head</code> ，只能直接访问 <strong>要被删除的节点</strong> 。</p>

<p>题目数据保证需要删除的节点 <strong>不是末尾节点</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/01/node1.jpg" style="height: 215px; width: 300px;" />
<pre>
<strong>输入：</strong>head = [4,5,1,9], node = 5
<strong>输出：</strong>[4,1,9]
<strong>解释：</strong>指定链表中值为&nbsp;5&nbsp;的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -&gt; 1 -&gt; 9
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/01/node2.jpg" style="height: 236px; width: 300px;" />
<pre>
<strong>输入：</strong>head = [4,5,1,9], node = 1
<strong>输出：</strong>[4,5,9]
<strong>解释：</strong>指定链表中值为&nbsp;1&nbsp;的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -&gt; 5 -&gt; 9</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目范围是 <code>[2, 1000]</code></li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
	<li>链表中每个节点的值都是 <strong>唯一</strong> 的</li>
	<li>需要删除的节点 <code>node</code> 是 <strong>链表中的节点</strong> ，且 <strong>不是末尾节点</strong></li>
</ul>


## 题解

### cpp [🔗](delete-node-in-a-linked-list.cpp) 
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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
```


## 相关话题

- [链表](https://leetcode-cn.com/tag/linked-list) 


## 相似题目

- [移除链表元素](../remove-linked-list-elements/README.md)  [Easy] 


## Links

- [Prev](../lowest-common-ancestor-of-a-binary-tree/README.md) 
- [Next](../product-of-array-except-self/README.md) 

