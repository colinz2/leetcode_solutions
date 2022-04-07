
# [](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree)

## 题目描述



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
        if (root == nullptr) return 0;
        return std::max(maxDepth(root->right), maxDepth(root->left)) + 1;
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



## 相似题目



## Links

- [Prev](../binary-tree-zigzag-level-order-traversal/README.md) 
- [Next](../binary-tree-level-order-traversal-ii/README.md) 

