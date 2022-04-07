
# [二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum)

## 题目描述

<p><strong>路径</strong> 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 <strong>至多出现一次</strong> 。该路径<strong> 至少包含一个 </strong>节点，且不一定经过根节点。</p>

<p><strong>路径和</strong> 是路径中各节点值的总和。</p>

<p>给你一个二叉树的根节点 <code>root</code> ，返回其 <strong>最大路径和</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/13/exx1.jpg" style="width: 322px; height: 182px;" />
<pre>
<strong>输入：</strong>root = [1,2,3]
<strong>输出：</strong>6
<strong>解释：</strong>最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/13/exx2.jpg" />
<pre>
<strong>输入：</strong>root = [-10,9,20,null,null,15,7]
<strong>输出：</strong>42
<strong>解释：</strong>最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目范围是 <code>[1, 3 * 10<sup>4</sup>]</code></li>
	<li><code>-1000 <= Node.val <= 1000</code></li>
</ul>


## 题解

### golang [🔗](binary-tree-maximum-path-sum.go) 
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxPathSum(root *TreeNode) int {
    res := -1<<31
    var dfs func(root *TreeNode) int = nil
    dfs = func(root *TreeNode) int {
        if root == nil {
            return 0
        }
        x := max(0, dfs(root.Left))
        y := max(0, dfs(root.Right))
        res = max(res, x + y + root.Val)
        return max(x, y) + root.Val
    }
    dfs(root)
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```
### cpp [🔗](binary-tree-maximum-path-sum.cpp) 
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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        calculateSum(root, res);
        return res;
    }

    int calculateSum(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        int s1 = calculateSum(root->left, res);
        int s2 = calculateSum(root->right, res);
        s1 = max(0, s1);
        s2 = max(0, s2);
        res = max(res, s1 + s2 + root->val);
        return max(s1, s2) + root->val;
    }
};
```


## 相关话题

- [树](../../tags/tree.md) 
- [深度优先搜索](../../tags/depth-first-search.md) 
- [动态规划](../../tags/dynamic-programming.md) 
- [二叉树](../../tags/binary-tree.md) 


## 相似题目

- [路径总和](../path-sum/README.md)  [Easy] 
- [求根节点到叶节点数字之和](../sum-root-to-leaf-numbers/README.md)  [Medium] 


## Links

- [Prev](../best-time-to-buy-and-sell-stock-ii/README.md) 
- [Next](../valid-palindrome/README.md) 

