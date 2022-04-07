
# [二叉树中第二小的节点](https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree)

## 题目描述

<p>给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为&nbsp;<code>2</code>&nbsp;或&nbsp;<code>0</code>。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。</p>

<p>更正式地说，即&nbsp;<code>root.val = min(root.left.val, root.right.val)</code> 总成立。</p>

<p>给出这样的一个二叉树，你需要输出所有节点中的&nbsp;<strong>第二小的值 </strong>。</p>

<p>如果第二小的值不存在的话，输出 -1 <strong>。</strong></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/15/smbt1.jpg" style="height: 210px; width: 300px;" />
<pre>
<strong>输入：</strong>root = [2,2,5,null,null,5,7]
<strong>输出：</strong>5
<strong>解释：</strong>最小的值是 2 ，第二小的值是 5 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/15/smbt2.jpg" style="height: 113px; width: 200px;" />
<pre>
<strong>输入：</strong>root = [2,2,2]
<strong>输出：</strong>-1
<strong>解释：</strong>最小的值是 2, 但是不存在第二小的值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[1, 25]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 2<sup>31</sup> - 1</code></li>
	<li>对于树中每个节点 <code>root.val == min(root.left.val, root.right.val)</code></li>
</ul>


## 题解

### cpp [🔗](second-minimum-node-in-a-binary-tree.cpp) 
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
    int findSecondMinimumValue(TreeNode* root) {
        int second = -1;
        std::function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == nullptr) {
                return;
            }
            if (second != -1 && second <= node->val) {
                return;
            }
            if (node->val > root->val) {
                second = node->val;
            }

            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        return second;
    }
};

```


## 相关话题

- [树](../../tags/tree.md) 
- [深度优先搜索](../../tags/depth-first-search.md) 
- [二叉树](../../tags/binary-tree.md) 


## 相似题目

- [二叉搜索树中第K小的元素](../kth-smallest-element-in-a-bst/README.md)  [Medium] 


## Links

- [Prev](../image-smoother/README.md) 
- [Next](../redundant-connection/README.md) 

