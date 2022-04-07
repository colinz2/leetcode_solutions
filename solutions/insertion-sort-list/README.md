
# [对链表进行插入排序](https://leetcode-cn.com/problems/insertion-sort-list)

## 题目描述

<p>给定单个链表的头<meta charset="UTF-8" />&nbsp;<code>head</code>&nbsp;，使用 <strong>插入排序</strong> 对链表进行排序，并返回&nbsp;<em>排序后链表的头</em>&nbsp;。</p>

<p><strong>插入排序</strong>&nbsp;算法的步骤:</p>

<ol>
	<li>插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。</li>
	<li>每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。</li>
	<li>重复直到所有输入数据插入完为止。</li>
</ol>

<p>下面是插入排序算法的一个图形示例。部分排序的列表(黑色)最初只包含列表中的第一个元素。每次迭代时，从输入数据中删除一个元素(红色)，并就地插入已排序的列表中。</p>

<p>对链表进行插入排序。</p>

<p><img alt="" src="https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif" /></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/03/04/sort1linked-list.jpg" /></p>

<pre>
<strong>输入:</strong> head = [4,2,1,3]
<strong>输出:</strong> [1,2,3,4]</pre>

<p><strong>示例&nbsp;2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/03/04/sort2linked-list.jpg" /></p>

<pre>
<strong>输入:</strong> head = [-1,5,3,4,0]
<strong>输出:</strong> [-1,0,3,4,5]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li>列表中的节点数在&nbsp;<code>[1, 5000]</code>范围内</li>
	<li><code>-5000 &lt;= Node.val &lt;= 5000</code></li>
</ul>


## 题解

### cpp [🔗](insertion-sort-list.cpp) 
```cpp
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* lastSorted = head;
        ListNode* curr = head->next;
        while (curr != nullptr) {
            if (lastSorted->val <= curr->val) {
                lastSorted = lastSorted->next;
            } else {
                ListNode *prev = dummyHead;
                while (prev->next->val <= curr->val) {
                    prev = prev->next;
                }
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = lastSorted->next;
        }
        return dummyHead->next;
    }
};


```


## 相关话题

- [链表](../../tags/linked-list.md) 
- [排序](../../tags/sorting.md) 


## 相似题目

- [排序链表](../sort-list/README.md)  [Medium] 
- [循环有序列表的插入](../insert-into-a-sorted-circular-linked-list/README.md)  [Medium] 


## Links

- [Prev](../lru-cache/README.md) 
- [Next](../sort-list/README.md) 

