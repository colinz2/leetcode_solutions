
# [环路检测](https://leetcode-cn.com/problems/linked-list-cycle-lcci)

## 题目描述

<p>给定一个链表，如果它是有环链表，实现一个算法返回环路的<code>开头节点</code>。若环不存在，请返回 <code>null</code>。</p>

<p>如果链表中有某个节点，可以通过连续跟踪 <code>next</code> 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 <code>pos</code> 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 <code>pos</code> 是 <code>-1</code>，则在该链表中没有环。<strong>注意：<code>pos</code> 不作为参数进行传递</strong>，仅仅是为了标识链表的实际情况。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png" style="height: 97px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>head = [3,2,0,-4], pos = 1
<strong>输出：</strong>tail connects to node index 1
<strong>解释：</strong>链表中有一个环，其尾部连接到第二个节点。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png" style="height: 74px; width: 141px;" /></p>

<pre>
<strong>输入：</strong>head = [1,2], pos = 0
<strong>输出：</strong>tail connects to node index 0
<strong>解释：</strong>链表中有一个环，其尾部连接到第一个节点。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png" style="height: 45px; width: 45px;" /></p>

<pre>
<strong>输入：</strong>head = [1], pos = -1
<strong>输出：</strong>no cycle
<strong>解释：</strong>链表中没有环。</pre>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你是否可以不用额外空间解决此题？</li>
</ul>

<p>&nbsp;</p>


## 题解

### cpp [🔗](linked-list-cycle-lcci.cpp) 
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
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> listSet;
        while (head) {
            if (listSet.count(head) != 0) {
                return head;
            }
            listSet.insert(head);
            head = head->next; 
        }
        return nullptr;
    }
};
```
### golang [🔗](linked-list-cycle-lcci.go) 
```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func detectCycle(head *ListNode) *ListNode {
    nodeMap := make(map[*ListNode]struct{})
    for head != nil {
        if _, e := nodeMap[head]; e {
            return head;
        }
        nodeMap[head] = struct{}{}
        head = head.Next
    }   
    return nil
}
```


## 相关话题

- [哈希表](https://leetcode-cn.com/tag/hash-table) 
- [链表](https://leetcode-cn.com/tag/linked-list) 
- [双指针](https://leetcode-cn.com/tag/two-pointers) 


## 相似题目



## Links

- [Prev](../is-unique-lcci/README.md) 
- [Next](../minimum-height-tree-lcci/README.md) 

