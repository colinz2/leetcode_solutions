
# [翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree)

## 题目描述

<p>给你一棵二叉树的根节点 <code>root</code> ，翻转这棵二叉树，并返回其根节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg" style="height: 165px; width: 500px;" /></p>

<pre>
<strong>输入：</strong>root = [4,2,7,1,3,6,9]
<strong>输出：</strong>[4,7,2,9,6,3,1]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg" style="width: 500px; height: 120px;" /></p>

<pre>
<strong>输入：</strong>root = [2,1,3]
<strong>输出：</strong>[2,3,1]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目范围在 <code>[0, 100]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>


## 题解

### cpp [🔗](invert-binary-tree.cpp) 
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            std::swap(node->right, node->left);
            if (node->right) q.push(node->right);
            if (node->left) q.push(node->left);
        }
        return root;
    }
};
```
### c [🔗](invert-binary-tree.c) 
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL) return root;
    invertTree(root->left);
    invertTree(root->right);
    struct TreeNode* tmp;
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    return root;
}
```


## 相关话题

- [树](../../tags/tree.md) 
- [深度优先搜索](../../tags/depth-first-search.md) 
- [广度优先搜索](../../tags/breadth-first-search.md) 
- [二叉树](../../tags/binary-tree.md) 


## 相似题目



## Links

- [Prev](../implement-stack-using-queues/README.md) 
- [Next](../summary-ranges/README.md) 

