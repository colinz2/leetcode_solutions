
# [二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree)

## 题目描述

<p>给定一个二叉树，找出其最大深度。</p>

<p>二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。</p>

<p><strong>说明:</strong>&nbsp;叶子节点是指没有子节点的节点。</p>

<p><strong>示例：</strong><br>
给定二叉树 <code>[3,9,20,null,null,15,7]</code>，</p>

<pre>    3
   / \
  9  20
    /  \
   15   7</pre>

<p>返回它的最大深度&nbsp;3 。</p>


## 题解

### cpp [🔗](maximum-depth-of-binary-tree.cpp) 
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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto level_size = q.size();
            for (auto i = 0; i < level_size; i++) {
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            depth++;
        }

        return depth;
    }
};
```
### golang [🔗](maximum-depth-of-binary-tree.go) 
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxDepth(root *TreeNode) int {
    if root ==  nil {
        return 0
    }
    return max(maxDepth(root.Left), maxDepth(root.Right)) + 1
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b;
}
```


## 相关话题

- [树](https://leetcode-cn.com/tag/tree) 
- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 
- [广度优先搜索](https://leetcode-cn.com/tag/breadth-first-search) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目

- [平衡二叉树](../balanced-binary-tree/README.md)  [Easy] 
- [二叉树的最小深度](../minimum-depth-of-binary-tree/README.md)  [Easy] 
- [N 叉树的最大深度](../maximum-depth-of-n-ary-tree/README.md)  [Easy] 


## Links

- [Prev](../binary-tree-level-order-traversal/README.md) 
- [Next](../binary-tree-level-order-traversal-ii/README.md) 

