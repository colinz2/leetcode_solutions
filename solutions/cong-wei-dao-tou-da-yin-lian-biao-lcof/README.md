
# [从尾到头打印链表](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof)

## 题目描述

<p>输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>head = [1,3,2]
<strong>输出：</strong>[2,3,1]</pre>

<p>&nbsp;</p>

<p><strong>限制：</strong></p>

<p><code>0 &lt;= 链表长度 &lt;= 10000</code></p>


## 题解

### cpp [🔗](cong-wei-dao-tou-da-yin-lian-biao-lcof.cpp) 
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
private:
    void recursion(ListNode*head, vector<int>& res){
        if (head==NULL) return;

        recursion(head->next, res);
        res.push_back(head->val);
    }
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        recursion(head, res);
        return res;
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

- [Prev](../ti-huan-kong-ge-lcof/README.md) 
- [Next](../he-bing-liang-ge-pai-xu-de-lian-biao-lcof/README.md) 

