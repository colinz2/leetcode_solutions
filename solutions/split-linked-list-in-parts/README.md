
# [分隔链表](https://leetcode-cn.com/problems/split-linked-list-in-parts)

## 题目描述

<p>给你一个头结点为 <code>head</code> 的单链表和一个整数 <code>k</code> ，请你设计一个算法将链表分隔为 <code>k</code> 个连续的部分。</p>

<p>每部分的长度应该尽可能的相等：任意两部分的长度差距不能超过 1 。这可能会导致有些部分为 null 。</p>

<p>这 <code>k</code> 个部分应该按照在链表中出现的顺序排列，并且排在前面的部分的长度应该大于或等于排在后面的长度。</p>

<p>返回一个由上述 <code>k</code> 部分组成的数组。</p>
&nbsp;

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/split1-lc.jpg" style="width: 400px; height: 134px;" />
<pre>
<strong>输入：</strong>head = [1,2,3], k = 5
<strong>输出：</strong>[[1],[2],[3],[],[]]
<strong>解释：</strong>
第一个元素 output[0] 为 output[0].val = 1 ，output[0].next = null 。
最后一个元素 output[4] 为 null ，但它作为 ListNode 的字符串表示是 [] 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/split2-lc.jpg" style="width: 600px; height: 60px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,4,5,6,7,8,9,10], k = 3
<strong>输出：</strong>[[1,2,3,4],[5,6,7],[8,9,10]]
<strong>解释：</strong>
输入被分成了几个连续的部分，并且每部分的长度相差不超过 1 。前面部分的长度大于等于后面部分的长度。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目在范围 <code>[0, 1000]</code></li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= 50</code></li>
</ul>


## 题解

### cpp [🔗](split-linked-list-in-parts.cpp) 
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k);
        if (head == nullptr) return res;
        int llen = 0;
        ListNode* curr = head;
        while (curr) {
            curr = curr->next;
            llen++;
        }
        
        ListNode* h = head;
        int plen = llen / k, rlen = llen % k;
        for (int i = 0; i < k; i++) {
            res[i] = h;
            for (int j = 1; j < plen +(i <rlen) && h; j++) {
                h = h->next;
            }
            if (h == nullptr) break;
            auto n = h->next;
            h->next = nullptr;
            h = n;
        }
        return res;
    }
};
```
### python3 [🔗](split-linked-list-in-parts.py) 
```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: ListNode, k: int) -> List[ListNode]:
        res = [None for _ in range(k)]
        if head == None:
            return res

        list_len = 0
        curr = head
        while curr:
            curr = curr.next
            list_len += 1
        psize = list_len // k
        rsize = list_len % k

        curr = head
        for i in range(k):
            if curr == None:
                break

            res[i] = curr        
            j = 1
            while j < psize + (1 if i < rsize else 0):
                curr = curr.next
                j += 1
            
            if curr:
                next_node = curr.next
                curr.next = None
                curr = next_node
        
        return res
```


## 相关话题

- [链表](../../tags/linked-list.md) 


## 相似题目

- [旋转链表](../rotate-list/README.md)  [Medium] 
- [奇偶链表](../odd-even-linked-list/README.md)  [Medium] 


## Links

- [Prev](../find-pivot-index/README.md) 
- [Next](../daily-temperatures/README.md) 

