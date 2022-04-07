
# [二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list)

## 题目描述

<p>给你二叉树的根结点 <code>root</code> ，请你将它展开为一个单链表：</p>

<ul>
	<li>展开后的单链表应该同样使用 <code>TreeNode</code> ，其中 <code>right</code> 子指针指向链表中下一个结点，而左子指针始终为 <code>null</code> 。</li>
	<li>展开后的单链表应该与二叉树 <a href="https://baike.baidu.com/item/%E5%85%88%E5%BA%8F%E9%81%8D%E5%8E%86/6442839?fr=aladdin" target="_blank"><strong>先序遍历</strong></a> 顺序相同。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/14/flaten.jpg" style="width: 500px; height: 226px;" />
<pre>
<strong>输入：</strong>root = [1,2,5,3,4,null,6]
<strong>输出：</strong>[1,null,2,null,3,null,4,null,5,null,6]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [0]
<strong>输出：</strong>[0]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中结点数在范围 <code>[0, 2000]</code> 内</li>
	<li><code>-100 <= Node.val <= 100</code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>你可以使用原地算法（<code>O(1)</code> 额外空间）展开这棵树吗？</p>


## 题解

### cpp [🔗](flatten-binary-tree-to-linked-list.cpp) 
```cpp
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
    void flatten(TreeNode* root) {
        std::vector<TreeNode*> vec;
        std::function<void(TreeNode*)> f1 = [&](TreeNode* node) {
            if (node == nullptr) {
                return;
            }
            vec.push_back(node);
            f1(node->left);
            f1(node->right);
        };
        f1(root);

        for (int i = 1; i < vec.size(); i++) {
            vec[i]->left = nullptr;
            vec[i]->right = nullptr;
            vec[i-1]->left = nullptr;
            vec[i-1]->right = vec[i];
        }
    }
};
```
### c [🔗](flatten-binary-tree-to-linked-list.c) 
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten_recur(struct TreeNode* root, struct TreeNode** last) {
    if (root == NULL) {
        return;
    }
    flatten_recur(root->right, last);
    flatten_recur(root->left, last);
    root->right = *last;
    root->left = NULL;
    *last = root;
}

void flatten(struct TreeNode* root){
    struct TreeNode* last = NULL;
    flatten_recur(root, &last);
}
```


## 相关话题

- [栈](https://leetcode-cn.com/tag/stack) 
- [树](https://leetcode-cn.com/tag/tree) 
- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 
- [链表](https://leetcode-cn.com/tag/linked-list) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目

- [扁平化多级双向链表](../flatten-a-multilevel-doubly-linked-list/README.md)  [Medium] 


## Links

- [Prev](../path-sum/README.md) 
- [Next](../populating-next-right-pointers-in-each-node/README.md) 

