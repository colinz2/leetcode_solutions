
# [循环有序列表的插入](https://leetcode-cn.com/problems/insert-into-a-sorted-circular-linked-list)

## 题目描述

<p>给定<strong>循环单调非递减列表</strong>中的一个点，写一个函数向这个列表中插入一个新元素&nbsp;<code>insertVal</code> ，使这个列表仍然是循环非降序的。</p>

<p>给定的可以是这个列表中任意一个顶点的指针，并不一定是这个列表中最小元素的指针。</p>

<p>如果有多个满足条件的插入位置，你可以选择任意一个位置插入新的值，插入后整个列表仍然保持有序。</p>

<p>如果列表为空（给定的节点是 <code>null</code>），你需要创建一个循环有序列表并返回这个节点。否则。请返回原先给定的节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/01/19/example_1_before_65p.jpg" style="height: 149px; width: 250px;" /><br />
&nbsp;
<pre>
<strong>输入：</strong>head = [3,4,1], insertVal = 2
<strong>输出：</strong>[3,4,1,2]
<strong>解释：</strong>在上图中，有一个包含三个元素的循环有序列表，你获得值为 3 的节点的指针，我们需要向表中插入元素 2 。新插入的节点应该在 1 和 3 之间，插入之后，整个列表如上图所示，最后返回节点 3 。

<img alt="" src="https://assets.leetcode.com/uploads/2019/01/19/example_1_after_65p.jpg" style="height: 149px; width: 250px;" />
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = [], insertVal = 1
<strong>输出：</strong>[1]
<strong>解释：</strong>列表为空（给定的节点是 <code>null</code>），创建一个循环有序列表并返回这个节点。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>head = [1], insertVal = 0
<strong>输出：</strong>[1,0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= Number of Nodes &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>6</sup> &lt;= Node.val, insertVal &lt;= 10<sup>6</sup></code></li>
</ul>


## 题解

### cpp [🔗](insert-into-a-sorted-circular-linked-list.cpp) 
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        Node* curr = head;
        while (curr->next != head) {
            if (curr->val <= insertVal && insertVal <= curr->next->val) {
                break;
            }
            if (curr->val > curr->next->val) {
                if (curr->val <= insertVal || curr->next->val >= insertVal) {
                    break;
                }
            }
            curr = curr->next;
        }
        Node* node = new Node(insertVal, curr->next);
        curr->next = node;
        return head;
    }
};
```


## 相关话题

- [链表](https://leetcode-cn.com/tag/linked-list) 


## 相似题目

- [对链表进行插入排序](../insertion-sort-list/README.md)  [Medium] 


## Links

- [Prev](../design-linked-list/README.md) 
- [Next](../design-circular-queue/README.md) 

