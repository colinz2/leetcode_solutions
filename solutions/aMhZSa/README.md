
# [回文链表](https://leetcode-cn.com/problems/aMhZSa)

## 题目描述

<p>给定一个链表的 <strong>头节点&nbsp;</strong><code>head</code><strong>&nbsp;，</strong>请判断其是否为回文链表。</p>

<p>如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://pic.leetcode-cn.com/1626421737-LjXceN-image.png" /></strong></p>

<pre>
<strong>输入:</strong> head = [1,2,3,3,2,1]
<strong>输出:</strong> true</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://pic.leetcode-cn.com/1626422231-wgvnWh-image.png" style="width: 138px; height: 62px;" /></strong></p>

<pre>
<strong>输入:</strong> head = [1,2]
<strong>输出:</strong> false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表 L 的长度范围为 <code>[1, 10<sup><span style="font-size: 9.449999809265137px;">5</span></sup>]</code></li>
	<li><code>0&nbsp;&lt;= node.val &lt;= 9</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>能否用&nbsp;O(n) 时间复杂度和 O(1) 空间复杂度解决此题？</p>

<p>&nbsp;</p>

<p><meta charset="UTF-8" />注意：本题与主站 234&nbsp;题相同：<a href="https://leetcode-cn.com/problems/palindrome-linked-list/">https://leetcode-cn.com/problems/palindrome-linked-list/</a></p>


## 题解

### c [🔗](aMhZSa.c) 
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    if (head == NULL) return false;
    if (head->next == NULL) return true;
    struct ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode* pre = NULL, *next = NULL;
    while (slow) {
        next = slow->next;
        slow->next = pre;
        pre = slow;
        slow = next;
    }

    while (pre && head) {
        if (pre->val != head->val) {
            return false;
        }
        pre = pre->next;
        head = head->next;
    }
    return true;
}
```
### cpp [🔗](aMhZSa.cpp) 
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
    bool isPalindrome(ListNode* head) {
        vector<ListNode*> vec;
        while (head) {
            vec.emplace_back(head);
            head = head->next;
        }

        for (int i = 0; i < vec.size()/2; i++) {
            if (vec[i]->val != vec[vec.size() - 1 -i]->val) {
                return false;
            }
        }
        return true;
    }
};
```


## 相关话题

- [栈](https://leetcode-cn.com/tag/stack) 
- [递归](https://leetcode-cn.com/tag/recursion) 
- [链表](https://leetcode-cn.com/tag/linked-list) 
- [双指针](https://leetcode-cn.com/tag/two-pointers) 


## 相似题目



## Links

- [Prev](../UHnkqh/README.md) 
- [Next](../iIQa4I/README.md) 

