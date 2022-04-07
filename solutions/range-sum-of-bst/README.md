
# [二叉搜索树的范围和](https://leetcode-cn.com/problems/range-sum-of-bst)

## 题目描述

<p>给定二叉搜索树的根结点 <code>root</code>，返回值位于范围 <em><code>[low, high]</code></em> 之间的所有结点的值的和。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/bst1.jpg" style="width: 400px; height: 222px;" />
<pre>
<strong>输入：</strong>root = [10,5,15,3,7,null,18], low = 7, high = 15
<strong>输出：</strong>32
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/bst2.jpg" style="width: 400px; height: 335px;" />
<pre>
<strong>输入：</strong>root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
<strong>输出：</strong>23
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[1, 2 * 10<sup>4</sup>]</code> 内</li>
	<li><code>1 <= Node.val <= 10<sup>5</sup></code></li>
	<li><code>1 <= low <= high <= 10<sup>5</sup></code></li>
	<li>所有 <code>Node.val</code> <strong>互不相同</strong></li>
</ul>


## 题解

### cpp [🔗](range-sum-of-bst.cpp) 
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        dfs(root, low, high, res);
        return res;
    }

    void dfs(TreeNode* root, int low, int high, int& res) {
        if (root == nullptr) return;
        if (root->val >= low && root->val <= high) {
            res += root->val;
            dfs(root->left, low, high, res);
            dfs(root->right, low, high, res);
        } else if (root->val < low) {
            dfs(root->right, low, high, res);
        } else {
            dfs(root->left, low, high, res);
        }
    }
};
```
### golang [🔗](range-sum-of-bst.go) 
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rangeSumBST(root *TreeNode, low int, high int) int {
    res := 0
    stack := []*TreeNode{}
    for root != nil || len(stack) > 0 {
        for root != nil {
            stack = append(stack, root)
            root = root.Left
        }
        root = stack[len(stack) - 1]
        stack = stack[:len(stack) - 1]
        if (root.Val >= low && root.Val <= high) {
            res += root.Val
        } else if (root.Val > high) {
            // 可以提前退出
            break;
        }
        root = root.Right
    }
    return res
}
```
### c [🔗](range-sum-of-bst.c) 
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int rangeSumBST(struct TreeNode* root, int low, int high){
    if (root == NULL) return 0;
    if (root->val < low) {
        return rangeSumBST(root->right, low, high);
    } else if (root->val > high) {
        return rangeSumBST(root->left, low, high);
    }
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}
```


## 相关话题

- [树](../../tags/tree.md) 
- [深度优先搜索](../../tags/depth-first-search.md) 
- [二叉搜索树](../../tags/binary-search-tree.md) 
- [二叉树](../../tags/binary-tree.md) 


## 相似题目



## Links

- [Prev](../number-of-recent-calls/README.md) 
- [Next](../univalued-binary-tree/README.md) 

