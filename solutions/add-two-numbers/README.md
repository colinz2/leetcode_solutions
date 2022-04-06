
# [两数相加](https://leetcode-cn.com/problems/add-two-numbers)

## 题目描述

<p>给你两个 <strong>非空</strong> 的链表，表示两个非负的整数。它们每位数字都是按照 <strong>逆序</strong> 的方式存储的，并且每个节点只能存储 <strong>一位</strong> 数字。</p>

<p>请你将两个数相加，并以相同形式返回一个表示和的链表。</p>

<p>你可以假设除了数字 0 之外，这两个数都不会以 0 开头。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/01/02/addtwonumber1.jpg" style="width: 483px; height: 342px;" />
<pre>
<strong>输入：</strong>l1 = [2,4,3], l2 = [5,6,4]
<strong>输出：</strong>[7,0,8]
<strong>解释：</strong>342 + 465 = 807.
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>l1 = [0], l2 = [0]
<strong>输出：</strong>[0]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
<strong>输出：</strong>[8,9,9,9,0,0,0,1]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>每个链表中的节点数在范围 <code>[1, 100]</code> 内</li>
	<li><code>0 <= Node.val <= 9</code></li>
	<li>题目数据保证列表表示的数字不含前导零</li>
</ul>


## 题解

### cpp [🔗](add-two-numbers.cpp) 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* l3 = &dummy;
        int add = 0;
        while (l1 || l2 || add) {
            if (l1) {
                add += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                add += l2->val;
                l2 = l2->next;
            }
            l3->next = new ListNode(add % 10);
            l3 = l3->next;
            add = add / 10; 
        }
        return dummy.next;
    }
};
```
### golang [🔗](add-two-numbers.go) 
```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	head := new(ListNode)
	carry, sum, curr := 0, 0, head

	for l1 != nil || l2 != nil || carry != 0 {
		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}
		curr.Next = &ListNode{
			Val:  sum % 10,
			Next: nil,
		}
		carry = sum / 10
		curr = curr.Next
		sum = carry
	}

	return head.Next
}

```


## 相关话题

- [递归](https://leetcode-cn.com/tag/recursion) 
- [链表](https://leetcode-cn.com/tag/linked-list) 
- [数学](https://leetcode-cn.com/tag/math) 


## 相似题目

- [字符串相乘](../multiply-strings/README.md)  [Medium] 
- [二进制求和](../add-binary/README.md)  [Easy] 
- [两整数之和](../sum-of-two-integers/README.md)  [Medium] 
- [字符串相加](../add-strings/README.md)  [Easy] 
- [两数相加 II](../add-two-numbers-ii/README.md)  [Medium] 


## Links

- [Prev](../two-sum/README.md) 
- [Next](../longest-substring-without-repeating-characters/README.md) 

