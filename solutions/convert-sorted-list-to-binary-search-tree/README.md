
# [有序链表转换二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree)

## 题目描述

<p>给定一个单链表的头节点 &nbsp;<code>head</code>&nbsp;，其中的元素 <strong>按升序排序</strong> ，将其转换为高度平衡的二叉搜索树。</p>

<p>本题中，一个高度平衡二叉树是指一个二叉树<em>每个节点&nbsp;</em>的左右两个子树的高度差不超过 1。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2020/08/17/linked.jpg" style="height: 388px; width: 500px;" /></p>

<pre>
<strong>输入:</strong> head = [-10,-3,0,5,9]
<strong>输出:</strong> [0,-3,9,-10,null,5]
<strong>解释:</strong> 一个可能的答案是[0，-3,9，-10,null,5]，它表示所示的高度平衡的二叉搜索树。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> head = []
<strong>输出:</strong> []
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>head</code>&nbsp;中的节点数在<code>[0, 2 * 10<sup>4</sup>]</code>&nbsp;范围内</li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


## 题解

### cpp [🔗](convert-sorted-list-to-binary-search-tree.cpp) 
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortListToBST(head, nullptr);
    }   

    TreeNode* sortListToBST(ListNode* head, ListNode* tail) {
        if (head == tail) {
            return nullptr;
        }
        ListNode* mid = head;
        ListNode* fast = head;
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            mid = mid->next;
        }
        TreeNode* node = new TreeNode(mid->val);
        node->left = sortListToBST(head, mid);
        node->right = sortListToBST(mid->next, tail);
        return node;
    }
};






```
### c [🔗](convert-sorted-list-to-binary-search-tree.c) 
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* sortedListToBST(struct ListNode* head){
    if (head == NULL) return NULL;
    struct ListNode *fast = head, *slow = head;
    struct ListNode** preSlow = &head;
    
    while (fast && fast->next) {
        fast = fast->next->next;
        preSlow = &(slow->next);
        slow = slow->next;
    }

    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = slow->val;
    *preSlow = NULL;
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(slow->next);
    return  node;
}
```


## 相关话题

- [树](https://leetcode-cn.com/tag/tree) 
- [二叉搜索树](https://leetcode-cn.com/tag/binary-search-tree) 
- [链表](https://leetcode-cn.com/tag/linked-list) 
- [分治](https://leetcode-cn.com/tag/divide-and-conquer) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目

- [将有序数组转换为二叉搜索树](../convert-sorted-array-to-binary-search-tree/README.md)  [Easy] 


## Links

- [Prev](../convert-sorted-array-to-binary-search-tree/README.md) 
- [Next](../balanced-binary-tree/README.md) 

