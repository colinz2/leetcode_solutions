
# [二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree)

## 题目描述

<p>给定一个二叉树，找出其最小深度。</p>

<p>最小深度是从根节点到最近叶子节点的最短路径上的节点数量。</p>

<p><strong>说明：</strong>叶子节点是指没有子节点的节点。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/12/ex_depth.jpg" style="width: 432px; height: 302px;" />
<pre>
<strong>输入：</strong>root = [3,9,20,null,null,15,7]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [2,null,3,null,4,null,5,null,6]
<strong>输出：</strong>5
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数的范围在 <code>[0, 10<sup>5</sup>]</code> 内</li>
	<li><code>-1000 <= Node.val <= 1000</code></li>
</ul>


## 题解

### cpp [🔗](minimum-depth-of-binary-tree.cpp) 
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
    int minDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int min = 0;

        q.push({root, 1});
        while (root !=  nullptr && !q.empty()) {
            auto tp = q.front(); q.pop();
            auto node = tp.first;
            auto level = tp.second;
            if (node->left == nullptr && node->right == nullptr) {
                return level;
            }
            if (node->left != nullptr) q.push({node->left, level + 1});
            if (node->right != nullptr) q.push({node->right, level + 1});
        }

        return min;
    }
};
```
### golang [🔗](minimum-depth-of-binary-tree.go) 
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func minDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    if root.Left == nil && root.Right == nil {
        return 1
    }

    lMinDepth := minDepth(root.Left)
    rMinDepth := minDepth(root.Right)
    if lMinDepth == 0 {
        // 左子树为空
        return rMinDepth + 1
    } 
    if rMinDepth == 0 {
        // 右子树为空
        return lMinDepth + 1
    }
    return min(lMinDepth, rMinDepth) + 1
}

func min(a, b int) int {
    if a > b {
        return b
    }
    return a
}
```


## 相关话题

- [树](https://leetcode-cn.com/tag/tree) 
- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 
- [广度优先搜索](https://leetcode-cn.com/tag/breadth-first-search) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目

- [二叉树的层序遍历](../binary-tree-level-order-traversal/README.md)  [Medium] 
- [二叉树的最大深度](../maximum-depth-of-binary-tree/README.md)  [Easy] 


## Links

- [Prev](../balanced-binary-tree/README.md) 
- [Next](../best-time-to-buy-and-sell-stock/README.md) 

