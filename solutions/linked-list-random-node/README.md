
# [链表随机节点](https://leetcode-cn.com/problems/linked-list-random-node)

## 题目描述

<p>给你一个单链表，随机选择链表的一个节点，并返回相应的节点值。每个节点<strong> 被选中的概率一样</strong> 。</p>

<p>实现 <code>Solution</code> 类：</p>

<ul>
	<li><code>Solution(ListNode head)</code> 使用整数数组初始化对象。</li>
	<li><code>int getRandom()</code> 从链表中随机选择一个节点并返回该节点的值。链表中所有节点被选中的概率相等。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/16/getrand-linked-list.jpg" style="width: 302px; height: 62px;" />
<pre>
<strong>输入</strong>
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
<strong>输出</strong>
[null, 1, 3, 2, 2, 3]

<strong>解释</strong>
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // 返回 1
solution.getRandom(); // 返回 3
solution.getRandom(); // 返回 2
solution.getRandom(); // 返回 2
solution.getRandom(); // 返回 3
// getRandom() 方法应随机返回 1、2、3中的一个，每个元素被返回的概率相等。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中的节点数在范围 <code>[1, 10<sup>4</sup>]</code> 内</li>
	<li><code>-10<sup>4</sup> &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>至多调用&nbsp;<code>getRandom</code> 方法 <code>10<sup>4</sup></code> 次</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>如果链表非常大且长度未知，该怎么处理？</li>
	<li>你能否在不使用额外空间的情况下解决此问题？</li>
</ul>


## 题解

### cpp [🔗](linked-list-random-node.cpp) 
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
    Solution(ListNode* head) {
        while (head) {
            vec_.push_back(head);
            head = head->next;
        }
    }
    
    int getRandom() {
        return vec_[rand() % vec_.size()]->val;
    }
private:
    std::vector<ListNode*> vec_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
```


## 相关话题

- [水塘抽样](../../tags/reservoir-sampling.md) 
- [链表](../../tags/linked-list.md) 
- [数学](../../tags/math.md) 
- [随机化](../../tags/randomized.md) 


## 相似题目



## Links

- [Prev](../guess-number-higher-or-lower/README.md) 
- [Next](../ransom-note/README.md) 

