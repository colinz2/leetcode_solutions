
# [求根节点到叶节点数字之和](https://leetcode-cn.com/problems/sum-root-to-leaf-numbers)

## 题目描述

给你一个二叉树的根节点 <code>root</code> ，树中每个节点都存放有一个 <code>0</code> 到 <code>9</code> 之间的数字。
<div class="original__bRMd">
<div>
<p>每条从根节点到叶节点的路径都代表一个数字：</p>

<ul>
	<li>例如，从根节点到叶节点的路径 <code>1 -> 2 -> 3</code> 表示数字 <code>123</code> 。</li>
</ul>

<p>计算从根节点到叶节点生成的 <strong>所有数字之和</strong> 。</p>

<p><strong>叶节点</strong> 是指没有子节点的节点。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/num1tree.jpg" style="width: 212px; height: 182px;" />
<pre>
<strong>输入：</strong>root = [1,2,3]
<strong>输出：</strong>25
<strong>解释：</strong>
从根到叶子节点路径 <code>1->2</code> 代表数字 <code>12</code>
从根到叶子节点路径 <code>1->3</code> 代表数字 <code>13</code>
因此，数字总和 = 12 + 13 = <code>25</code></pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/num2tree.jpg" style="width: 292px; height: 302px;" />
<pre>
<strong>输入：</strong>root = [4,9,0,5,1]
<strong>输出：</strong>1026
<strong>解释：</strong>
从根到叶子节点路径 <code>4->9->5</code> 代表数字 495
从根到叶子节点路径 <code>4->9->1</code> 代表数字 491
从根到叶子节点路径 <code>4->0</code> 代表数字 40
因此，数字总和 = 495 + 491 + 40 = <code>1026</code>
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 1000]</code> 内</li>
	<li><code>0 <= Node.val <= 9</code></li>
	<li>树的深度不超过 <code>10</code></li>
</ul>
</div>
</div>


## 题解

### golang [🔗](sum-root-to-leaf-numbers.go) 
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */


func sumNumbers(root *TreeNode) int {
    return helper(root, 0)
}

func helper(root *TreeNode, prev int) int {
    if root == nil {
        return 0
    }
    sum := 10*prev + root.Val
    if root.Left == nil && root.Right == nil {
        return sum
    }
    return helper(root.Left, sum) + helper(root.Right, sum)
}
```
### c [🔗](sum-root-to-leaf-numbers.c) 
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void sumNumbersDfs(struct TreeNode* root, int sumPrev, int *total) {
    if (root == NULL) return;
    int num = sumPrev*10 + root->val;
    if (root->left == NULL && root->right == NULL) {
        *total += num;
        return;
    }
    if (root->left) sumNumbersDfs(root->left, num, total);
    if (root->right) sumNumbersDfs(root->right, num, total);
}

int sumNumbers(struct TreeNode* root){
    int sum = 0;
    sumNumbersDfs(root, 0, &sum);
    return sum;
}
```


## 相关话题

- [树](https://leetcode-cn.com/tag/tree) 
- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目

- [路径总和](../path-sum/README.md)  [Easy] 
- [二叉树中的最大路径和](../binary-tree-maximum-path-sum/README.md)  [Hard] 


## Links

- [Prev](../longest-consecutive-sequence/README.md) 
- [Next](../surrounded-regions/README.md) 

