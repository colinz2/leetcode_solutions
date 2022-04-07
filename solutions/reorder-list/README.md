
# [重排链表](https://leetcode-cn.com/problems/reorder-list)

## 题目描述

<p>给定一个单链表 <code>L</code><em> </em>的头节点 <code>head</code> ，单链表 <code>L</code> 表示为：</p>

<pre>
L<sub>0</sub> → L<sub>1</sub> → … → L<sub>n - 1</sub> → L<sub>n</sub>
</pre>

<p>请将其重新排列后变为：</p>

<pre>
L<sub>0</sub> → L<sub>n</sub> → L<sub>1</sub> → L<sub>n - 1</sub> → L<sub>2</sub> → L<sub>n - 2</sub> → …</pre>

<p>不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://pic.leetcode-cn.com/1626420311-PkUiGI-image.png" style="width: 240px; " /></p>

<pre>
<strong>输入：</strong>head = [1,2,3,4]
<strong>输出：</strong>[1,4,2,3]</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://pic.leetcode-cn.com/1626420320-YUiulT-image.png" style="width: 320px; " /></p>

<pre>
<strong>输入：</strong>head = [1,2,3,4,5]
<strong>输出：</strong>[1,5,2,4,3]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表的长度范围为 <code>[1, 5 * 10<sup>4</sup>]</code></li>
	<li><code>1 &lt;= node.val &lt;= 1000</code></li>
</ul>


## 题解

### c [🔗](reorder-list.c) 
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


void reorderList(struct ListNode* head){
    // 1 分一半
    // 2 逆序
    // 3 合并
    if (head == NULL || head->next == NULL) return head;
    // 1
    struct ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode *l2 = slow->next, *l1 = head;
    slow->next = NULL;
    // 2
    struct ListNode *prev = NULL, *next = NULL;
    while (l2) {
        next = l2->next;
        l2->next = prev;
        prev = l2;
        l2 = next;
    }
    l2 = prev;
    // 3
    while (l1 && l2) {
        struct ListNode* l1next = l1->next;
        struct ListNode* l2next = l2->next;

        l2->next = l1next;
        l1->next = l2;
        l1 = l1next;
        l2 = l2next;
    }
    return head;
}
```
### cpp [🔗](reorder-list.cpp) 
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
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        vector<ListNode*> vec;
        while (head) {
            vec.push_back(head);
            head = head->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i++]->next = vec[j];
            if (i == j) break;
            vec[j--]->next = vec[i];
        }
        //这一步不能忘啊。
        vec[i]->next = nullptr;
    }
};
```


## 相关话题

- [栈](../../tags/stack.md) 
- [递归](../../tags/recursion.md) 
- [链表](../../tags/linked-list.md) 
- [双指针](../../tags/two-pointers.md) 


## 相似题目



## Links

- [Prev](../linked-list-cycle-ii/README.md) 
- [Next](../binary-tree-preorder-traversal/README.md) 

