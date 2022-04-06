
# [排序链表](https://leetcode-cn.com/problems/sort-list)

## 题目描述

<p>给你链表的头结点&nbsp;<code>head</code>&nbsp;，请将其按 <strong>升序</strong> 排列并返回 <strong>排序后的链表</strong> 。</p>

<ul>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/14/sort_list_1.jpg" style="width: 450px;" />
<pre>
<b>输入：</b>head = [4,2,1,3]
<b>输出：</b>[1,2,3,4]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/14/sort_list_2.jpg" style="width: 550px;" />
<pre>
<b>输入：</b>head = [-1,5,3,4,0]
<b>输出：</b>[-1,0,3,4,5]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>head = []
<b>输出：</b>[]
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li>链表中节点的数目在范围&nbsp;<code>[0, 5 * 10<sup>4</sup>]</code>&nbsp;内</li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><b>进阶：</b>你可以在&nbsp;<code>O(n&nbsp;log&nbsp;n)</code> 时间复杂度和常数级空间复杂度下，对链表进行排序吗？</p>


## 题解

### cpp [🔗](sort-list.cpp) 
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
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (head == NULL) {
            return head;
        }
        if (head->next == tail) {
            // set to nullptr
            head->next = nullptr;
            return head;
        }
        ListNode *fast = head, *slow = head;
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }

        auto l1 = sortList(head, slow);
        auto l2 = sortList(slow, tail);
        return merge(l1, l2);
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
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
        } else {
            l3->next = l2;
        }

        return dummy.next;
    }
};
```


## 相关话题

- [链表](https://leetcode-cn.com/tag/linked-list) 
- [双指针](https://leetcode-cn.com/tag/two-pointers) 
- [分治](https://leetcode-cn.com/tag/divide-and-conquer) 
- [排序](https://leetcode-cn.com/tag/sorting) 
- [归并排序](https://leetcode-cn.com/tag/merge-sort) 


## 相似题目

- [合并两个有序链表](../merge-two-sorted-lists/README.md)  [Easy] 
- [颜色分类](../sort-colors/README.md)  [Medium] 
- [对链表进行插入排序](../insertion-sort-list/README.md)  [Medium] 


## Links

- [Prev](../insertion-sort-list/README.md) 
- [Next](../evaluate-reverse-polish-notation/README.md) 

