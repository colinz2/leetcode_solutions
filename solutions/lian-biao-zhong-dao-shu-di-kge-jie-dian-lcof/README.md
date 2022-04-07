
# [链表中倒数第k个节点](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof)

## 题目描述

<p>输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。</p>

<p>例如，一个链表有 <code>6</code> 个节点，从头节点开始，它们的值依次是 <code>1、2、3、4、5、6</code>。这个链表的倒数第 <code>3</code> 个节点是值为 <code>4</code> 的节点。</p>

<p> </p>

<p><strong>示例：</strong></p>

<pre>
给定一个链表: <strong>1->2->3->4->5</strong>, 和 <em>k </em><strong>= 2</strong>.

返回链表 4<strong>->5</strong>.</pre>


## 题解

### cpp [🔗](lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof.cpp) 
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < k && fast; i++) {
            fast = fast->next;
        }
        while (fast && slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};
```
### golang [🔗](lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof.go) 
```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getKthFromEnd(head *ListNode, k int) *ListNode {
    fast := head
    slow := head
    for k > 0 && fast != nil {
        fast = fast.Next
        k--
    }

    for fast != nil {
        fast = fast.Next
        slow = slow.Next
    }

    return slow
}
```


## 相关话题

- [链表](../../tags/linked-list.md) 
- [双指针](../../tags/two-pointers.md) 


## 相似题目



## Links

- [Prev](../er-jin-zhi-zhong-1de-ge-shu-lcof/README.md) 
- [Next](../fan-zhuan-lian-biao-lcof/README.md) 

