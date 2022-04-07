
# [合并K个升序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists)

## 题目描述

<p>给你一个链表数组，每个链表都已经按升序排列。</p>

<p>请你将所有链表合并到一个升序链表中，返回合并后的链表。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>lists = [[1,4,5],[1,3,4],[2,6]]
<strong>输出：</strong>[1,1,2,3,4,4,5,6]
<strong>解释：</strong>链表数组如下：
[
  1-&gt;4-&gt;5,
  1-&gt;3-&gt;4,
  2-&gt;6
]
将它们合并到一个有序链表中得到。
1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4-&gt;5-&gt;6
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>lists = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>lists = [[]]
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>k == lists.length</code></li>
	<li><code>0 &lt;= k &lt;= 10^4</code></li>
	<li><code>0 &lt;= lists[i].length &lt;= 500</code></li>
	<li><code>-10^4 &lt;= lists[i][j] &lt;= 10^4</code></li>
	<li><code>lists[i]</code> 按 <strong>升序</strong> 排列</li>
	<li><code>lists[i].length</code> 的总和不超过 <code>10^4</code></li>
</ul>


## 题解

### cpp [🔗](merge-k-sorted-lists.cpp) 
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class CompareListNode{
public:
    bool operator()(ListNode* node1, ListNode* node2){
        return node1->val > node2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;

        ListNode* dummyHead = new ListNode(-1);
        ListNode* curNode = dummyHead;

        priority_queue<ListNode*, vector<ListNode*>, CompareListNode> q;
        for(ListNode* node: lists)
            if(node != NULL)
                q.push(node);

        while(!q.empty()){

            ListNode* nextNode = q.top();
            q.pop();


            curNode->next = nextNode;
            if(nextNode->next != NULL)
                q.push(nextNode->next);

            nextNode->next = NULL;
            curNode = curNode->next;
        }

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};
```


## 相关话题

- [链表](../../tags/linked-list.md) 
- [分治](../../tags/divide-and-conquer.md) 
- [堆（优先队列）](../../tags/heap-priority-queue.md) 
- [归并排序](../../tags/merge-sort.md) 


## 相似题目

- [合并两个有序链表](../merge-two-sorted-lists/README.md)  [Easy] 
- [丑数 II](../ugly-number-ii/README.md)  [Medium] 


## Links

- [Prev](../generate-parentheses/README.md) 
- [Next](../swap-nodes-in-pairs/README.md) 

