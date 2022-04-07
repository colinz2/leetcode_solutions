
# [回文链表](https://leetcode-cn.com/problems/palindrome-linked-list)

## 题目描述

<p>给你一个单链表的头节点 <code>head</code> ，请你判断该链表是否为回文链表。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg" style="width: 422px; height: 62px;" />
<pre>
<strong>输入：</strong>head = [1,2,2,1]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg" style="width: 182px; height: 62px;" />
<pre>
<strong>输入：</strong>head = [1,2]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点数目在范围<code>[1, 10<sup>5</sup>]</code> 内</li>
	<li><code>0 &lt;= Node.val &lt;= 9</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能否用&nbsp;<code>O(n)</code> 时间复杂度和 <code>O(1)</code> 空间复杂度解决此题？</p>


## 题解

### cpp [🔗](palindrome-linked-list.cpp) 
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
        std::vector<int> vec;
        while (head) {
            vec.push_back(head->val);
            head = head->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            if (vec[i++] != vec[j--]) {
                return false;
            }
        }
        return true;
    }
};
```


## 相关话题

- [栈](../../tags/stack.md) 
- [递归](../../tags/recursion.md) 
- [链表](../../tags/linked-list.md) 
- [双指针](../../tags/two-pointers.md) 


## 相似题目

- [回文数](../palindrome-number/README.md)  [Easy] 
- [验证回文串](../valid-palindrome/README.md)  [Easy] 
- [反转链表](../reverse-linked-list/README.md)  [Easy] 


## Links

- [Prev](../implement-queue-using-stacks/README.md) 
- [Next](../lowest-common-ancestor-of-a-binary-search-tree/README.md) 

