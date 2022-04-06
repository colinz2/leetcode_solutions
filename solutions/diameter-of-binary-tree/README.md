
# [二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree)

## 题目描述

<p>给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。</p>

<p>&nbsp;</p>

<p><strong>示例 :</strong><br>
给定二叉树</p>

<pre>          1
         / \
        2   3
       / \     
      4   5    
</pre>

<p>返回&nbsp;<strong>3</strong>, 它的长度是路径 [4,2,1,3] 或者&nbsp;[5,2,1,3]。</p>

<p>&nbsp;</p>

<p><strong>注意：</strong>两结点之间的路径长度是以它们之间边的数目表示。</p>


## 题解

### c [🔗](diameter-of-binary-tree.c) 
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int a, int b) {
    return a > b ? a : b;
}

int depthOfBinaryTree(struct TreeNode* root, int *diameter) {
    if (root == NULL) return 0;
    int dleft = depthOfBinaryTree(root->left, diameter);
    int dright = depthOfBinaryTree(root->right, diameter);
    *diameter = max(*diameter, dleft + dright);
    return max(dleft, dright) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    int diameter = 0;
    depthOfBinaryTree(root, &diameter);
    return diameter;
}
```
### cpp [🔗](diameter-of-binary-tree.cpp) 
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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        depth(root, res);
        return res;
    }

    int depth(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        int d1 = depth(root->left, res);
        int d2 = depth(root->right, res);
        res = std::max(res, d1 + d2);
        return std::max(d1, d2) + 1;
    }
};
```
### golang [🔗](diameter-of-binary-tree.go) 
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func diameterOfBinaryTree(root *TreeNode) int {
    diameter := 0
    depth(root, &diameter)
    return diameter
}

func depth(root *TreeNode, diameter *int) int {
    if root == nil {
        return 0
    }
    le := depth(root.Left, diameter)
    ri := depth(root.Right, diameter)
    *diameter = max(*diameter, le + ri)
    return max(le, ri) + 1
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}


```


## 相关话题

- [树](https://leetcode-cn.com/tag/tree) 
- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 


## 相似题目



## Links

- [Prev](../reverse-string-ii/README.md) 
- [Next](../number-of-provinces/README.md) 

