
# [二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal)

## 题目描述

<p>给你一棵二叉树的根节点 <code>root</code> ，返回其节点值的 <strong>后序遍历 </strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/pre1.jpg" style="width: 127px; height: 200px;" />
<pre>
<strong>输入：</strong>root = [1,null,2,3]
<strong>输出：</strong>[3,2,1]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[0, 100]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>递归算法很简单，你可以通过迭代算法完成吗？</p>


## 题解

### cpp [🔗](binary-tree-postorder-traversal.cpp) 
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;

        stack<TreeNode*> stack, output;

        TreeNode* p = root;
        while (p != NULL || !stack.empty()) {
            if (p != NULL) {
                stack.push(p);
                output.push(p);
                p = p->right;
            } else {
                p = stack.top();
                stack.pop();
                p = p->left;
            }
        }

        while (!output.empty()) {
            res.push_back((output.top())->val);
            output.pop();
        }
        return res;
    }
};

```


## 相关话题

- [栈](https://leetcode-cn.com/tag/stack) 
- [树](https://leetcode-cn.com/tag/tree) 
- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目

- [二叉树的中序遍历](../binary-tree-inorder-traversal/README.md)  [Easy] 


## Links

- [Prev](../binary-tree-preorder-traversal/README.md) 
- [Next](../lru-cache/README.md) 

