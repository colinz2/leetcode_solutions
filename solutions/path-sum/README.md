
# [路径总和](https://leetcode-cn.com/problems/path-sum)

## 题目描述

<p>给你二叉树的根节点&nbsp;<code>root</code> 和一个表示目标和的整数&nbsp;<code>targetSum</code> 。判断该树中是否存在 <strong>根节点到叶子节点</strong> 的路径，这条路径上所有节点值相加等于目标和&nbsp;<code>targetSum</code> 。如果存在，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p><strong>叶子节点</strong> 是指没有子节点的节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg" style="width: 500px; height: 356px;" />
<pre>
<strong>输入：</strong>root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
<strong>输出：</strong>true
<strong>解释：</strong>等于目标和的根节点到叶节点路径如上图所示。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg" />
<pre>
<strong>输入：</strong>root = [1,2,3], targetSum = 5
<strong>输出：</strong>false
<strong>解释：</strong>树中存在两条根节点到叶子节点的路径：
(1 --&gt; 2): 和为 3
(1 --&gt; 3): 和为 4
不存在 sum = 5 的根节点到叶子节点的路径。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [], targetSum = 0
<strong>输出：</strong>false
<strong>解释：</strong>由于树是空的，所以不存在根节点到叶子节点的路径。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[0, 5000]</code> 内</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
	<li><code>-1000 &lt;= targetSum &lt;= 1000</code></li>
</ul>


## 题解

### c [🔗](path-sum.c) 
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int targetSum){
    if (root == NULL) return false;
    if (!root->right && !root->left && root->val == targetSum) return true;
    int val = targetSum - root->val;
    return hasPathSum(root->left, val) || hasPathSum(root->right, val);
}
```
### cpp [🔗](path-sum.cpp) 
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        } 
        if (!root->left  && !root->right) {
            return targetSum == root->val;
        }
        int nextSum = targetSum - root->val;
        return hasPathSum(root->left, nextSum) || hasPathSum(root->right, nextSum);
    }
};
```


## 相关话题

- [树](https://leetcode-cn.com/tag/tree) 
- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 
- [广度优先搜索](https://leetcode-cn.com/tag/breadth-first-search) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目

- [二叉树中的最大路径和](../binary-tree-maximum-path-sum/README.md)  [Hard] 
- [求根节点到叶节点数字之和](../sum-root-to-leaf-numbers/README.md)  [Medium] 


## Links

- [Prev](../minimum-depth-of-binary-tree/README.md) 
- [Next](../flatten-binary-tree-to-linked-list/README.md) 

