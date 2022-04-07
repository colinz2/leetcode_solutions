
# [](https://leetcode-cn.com/problems/range-sum-of-bst)

## 题目描述



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



## 相似题目



## Links

- [Prev](../number-of-recent-calls/README.md) 
- [Next](../univalued-binary-tree/README.md) 

